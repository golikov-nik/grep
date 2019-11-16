#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent), ui(new Ui::grep) {
  ui->setupUi(this);
  ui->stopButton->setEnabled(false);
  connect(ui->fileEdit,
          &QLineEdit::textChanged,
          this,
          [this](QString const& new_file) {
            bg_thread.set_file(new_file);
          });
  connect(ui->directoryBrowseButton, &QPushButton::clicked, this, [this] {
    ui->fileEdit->setText(QFileDialog::getExistingDirectory(this,
            tr("Select directory")));
  });
  connect(ui->fileBrowseButton, &QPushButton::clicked, this, [this] {
    ui->fileEdit->setText(QFileDialog::getOpenFileName(this,
            tr("Select file")));
  });
  connect(ui->patternEdit,
          &QLineEdit::textChanged,
          this,
          [this](QString const& new_pattern) {
            bg_thread.set_pattern(new_pattern);
          });
  connect(ui->searchButton, &QPushButton::clicked, this, [this] {
    ui->searchButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
    bg_thread.process();
  });
  connect(ui->stopButton, &QPushButton::clicked, this, [this] {
    ui->searchButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
    bg_thread.stop();
  });
  connect(&bg_thread, &background_thread::result_changed, this, [this] {
    auto result = bg_thread.get_result();
    auto shown = ui->listWidget->count();
    if (result.occurrences.empty()) {
      ui->listWidget->clear();
    }
    for (size_t i = shown; i < result.occurrences.size(); ++i) {
      ui->listWidget->addItem(result.occurrences[i]);
    }
    auto info = QString("Found %1 occurrences, completed %2 files").arg(
            QString::number(result.found_matches),
            QString::number(result.completed_files));
    if (result.incomplete) {
      info += " and still way to go";
    } else {
      ui->searchButton->setEnabled(true);
      ui->stopButton->setEnabled(false);
    }
    ui->infoBrowser->setText(info);
  });
}

MainWindow::~MainWindow() {
  delete ui;
}
