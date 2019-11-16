/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
 public:
  QWidget *centralWidget;
  QGridLayout *gridLayout;
  QLineEdit *fileEdit;
  QPushButton *searchButton;
  QLineEdit *countEdit;
  QLabel *label_2;
  QListWidget *listWidget;
  QLabel *label;
  QLabel *label_3;
  QLineEdit *patternEdit;
  QPushButton *stopButton;
  QMenuBar *menuBar;
  QMenu *menugrep;
  QToolBar *mainToolBar;
  QStatusBar *statusBar;
  QToolBar *toolBar;

  void setupUi(QMainWindow *MainWindow)
  {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(489, 382);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    fileEdit = new QLineEdit(centralWidget);
    fileEdit->setObjectName(QStringLiteral("fileEdit"));

    gridLayout->addWidget(fileEdit, 1, 0, 1, 1);

    searchButton = new QPushButton(centralWidget);
    searchButton->setObjectName(QStringLiteral("searchButton"));

    gridLayout->addWidget(searchButton, 4, 0, 1, 1);

    countEdit = new QLineEdit(centralWidget);
    countEdit->setObjectName(QStringLiteral("countEdit"));

    gridLayout->addWidget(countEdit, 8, 0, 1, 1);

    label_2 = new QLabel(centralWidget);
    label_2->setObjectName(QStringLiteral("label_2"));

    gridLayout->addWidget(label_2, 2, 0, 1, 1);

    listWidget = new QListWidget(centralWidget);
    listWidget->setObjectName(QStringLiteral("listWidget"));

    gridLayout->addWidget(listWidget, 7, 0, 1, 1);

    label = new QLabel(centralWidget);
    label->setObjectName(QStringLiteral("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_3 = new QLabel(centralWidget);
    label_3->setObjectName(QStringLiteral("label_3"));

    gridLayout->addWidget(label_3, 6, 0, 1, 1);

    patternEdit = new QLineEdit(centralWidget);
    patternEdit->setObjectName(QStringLiteral("patternEdit"));

    gridLayout->addWidget(patternEdit, 3, 0, 1, 1);

    stopButton = new QPushButton(centralWidget);
    stopButton->setObjectName(QStringLiteral("stopButton"));

    gridLayout->addWidget(stopButton, 5, 0, 1, 1);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 489, 22));
    menugrep = new QMenu(menuBar);
    menugrep->setObjectName(QStringLiteral("menugrep"));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    MainWindow->setStatusBar(statusBar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QStringLiteral("toolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    menuBar->addAction(menugrep->menuAction());

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow)
  {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    searchButton->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
    label_2->setText(QApplication::translate("MainWindow", "Pattern", Q_NULLPTR));
    label->setText(QApplication::translate("MainWindow", "Input file", Q_NULLPTR));
    label_3->setText(QApplication::translate("MainWindow", "Result", Q_NULLPTR));
    stopButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    menugrep->setTitle(QApplication::translate("MainWindow", "grep", Q_NULLPTR));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
  } // retranslateUi

};

namespace Ui {
  class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
