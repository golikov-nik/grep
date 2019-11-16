#ifndef BACKGROUND_THREAD_H
#define BACKGROUND_THREAD_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>

class background_thread : public QObject {
 Q_OBJECT

  mutable std::mutex m;
  QString pattern;
  QString future_pattern;
  QString filename;
  QString future_filename;
  bool quit{};
  bool has_work{};
  bool callback_queued{};
  std::atomic_bool cancel{};
  std::condition_variable has_work_cv;
  std::thread thread;

 public:
  struct result_t {
    result_t() = default;

    std::vector<QString> occurrences;
    size_t found{};
    bool incomplete{};
  };

  background_thread();

  ~background_thread();

  void set_pattern(QString const& new_pattern);

  void set_file(QString const& new_filename);

  void process();

  void stop();

  result_t get_result() const;

 signals:

  void result_changed();

 private:
  void enqueue_callback();

  Q_INVOKABLE void callback();

  void work(QString const& p, QString const& path);

  result_t current_result;
};

#endif // BACKGROUND_THREAD_H
