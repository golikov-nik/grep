#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->fileEdit,
          &QLineEdit::textChanged,
          this,
          [this](QString const& new_file) {
            bg_thread.set_file(new_file);
          });
  connect(ui->patternEdit,
          &QLineEdit::textChanged,
          this,
          [this](QString const& new_pattern) {
            bg_thread.set_pattern(new_pattern);
          });
  connect(ui->searchButton, &QPushButton::clicked, this, [this] {
    bg_thread.process();
  });
  connect(ui->stopButton, &QPushButton::clicked, this, [this] {
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
    QString info = "Found ";
    info += QString::number(result.found);
    if (result.incomplete) {
      info += " and still way to go";
    }
    ui->countEdit->setText(info);
  });
}

MainWindow::~MainWindow() {
  delete ui;
}
