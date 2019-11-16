#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "background_thread.h"
#include "ui_mainwindow.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);

  ~MainWindow() override;

 private:
  Ui::grep* ui;
  background_thread bg_thread;
};

#endif // MAINWINDOW_H
