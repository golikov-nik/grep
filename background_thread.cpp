#include "background_thread.h"
#include <iostream>
#include <QtCore/QDirIterator>
#include <QDir>

background_thread::background_thread() : thread([this] {
  while (true) {
    std::unique_lock<std::mutex> lg(m);
    has_work_cv.wait(lg, [this] {
      return has_work || quit;
    });
    if (quit) {
      break;
    }
    auto new_pattern = pattern;
    auto new_filename = filename;

    current_result.incomplete = true;
    current_result.occurrences.clear();
    current_result.found_matches = 0;
    current_result.completed_files = 0;
    enqueue_callback();

    lg.unlock();
    work(new_pattern, new_filename);
    lg.lock();

    current_result.incomplete = cancel.load();
    enqueue_callback();

    has_work = false;
    cancel.store(false);
  }
}) {
}

background_thread::~background_thread() {
  cancel.store(true);
  {
    std::unique_lock<std::mutex> lg(m);
    quit = true;
    has_work_cv.notify_all();
  }
  thread.join();
}

void background_thread::set_pattern(QString const& new_pattern) {
  std::unique_lock<std::mutex> lg(m);
  future_pattern = new_pattern;
}

void background_thread::set_file(QString const& new_filename) {
  std::unique_lock<std::mutex> lg(m);
  future_filename = new_filename;
}

void background_thread::process() {
  std::unique_lock<std::mutex> lg(m);
  if (has_work) {
    return;
  }
  has_work = true;
  cancel.store(false);
  pattern = future_pattern;
  filename = future_filename;
  has_work_cv.notify_all();
}

void background_thread::stop() {
  std::unique_lock<std::mutex> lg(m);
  cancel.store(true);
}

background_thread::result_t background_thread::get_result() const {
  std::lock_guard<std::mutex> lg(m);
  return current_result;
}

void background_thread::enqueue_callback() {
  if (callback_queued) {
    return;
  }
  callback_queued = true;
  QMetaObject::invokeMethod(this, "callback", Qt::QueuedConnection);
}

void background_thread::callback() {
  {
    std::unique_lock<std::mutex> lg(m);
    callback_queued = false;
  }
  emit result_changed();
}

void background_thread::work(QString const& p, QString const& path) {
  if (cancel.load()) {
    return;
  }
  QDir directory(path);
  if (directory.exists()) {
    QDirIterator it(path,
                    QDir::Dirs
                    | QDir::AllEntries
                    | QDir::Files
                    | QDir::NoSymLinks
                    | QDir::NoDotAndDotDot
                    | QDir::Readable,
                    QDirIterator::Subdirectories);
    while (it.hasNext()) {
      if (cancel.load()) {
        return;
      }
      work(p, it.next());
    }
  }
  std::vector<int> pref;
  auto p_size = p.size();

  pref.reserve(p_size + 1);
  int k = -1;

  auto add_char = [&pref, &k, &p, p_size](auto ch) {
    while (k >= 0 && (k == p_size || ch != p[k])) {
      k = pref[k];
    }
    return ++k;
  };
  pref.push_back(k);
  for (auto ch : p) {
    if (cancel.load()) {
      return;
    }
    pref.push_back(add_char(ch));
  }

  QFile f(path);
  f.open(QIODevice::ReadOnly);
  if (!f.isOpen()) {
    return;
  }

  size_t constexpr BUFFER_SIZE = 1u << 20u;
  size_t constexpr MAX_RESULTS = 100;

  QTextStream stream(&f);
  QString buffer;

  k = 0;
  size_t line_number = 1;
  size_t pos = 1;
  if (cancel.load()) {
    return;
  }
  while (!stream.atEnd()) {
    buffer = stream.read(BUFFER_SIZE);
    if (cancel.load()) {
      return;
    }
    for (auto ch : buffer) {
      if (ch == '\n') {
        ++line_number;
        pos = 0;
      }
      if (add_char(ch) == p_size) {
        std::unique_lock<std::mutex> lg(m);
        ++current_result.found_matches;
        if (current_result.occurrences.size() < MAX_RESULTS) {
          QString res = QString("%1 %2:%3").arg(path,
                                                QString::number(line_number),
                                                QString::number(pos));
          current_result.occurrences.push_back(res);
        }
        enqueue_callback();
      }
      ++pos;
    }
  }
  std::unique_lock<std::mutex> lg(m);
  ++current_result.completed_files;
  enqueue_callback();
}
