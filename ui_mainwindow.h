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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grep
{
 public:
  QWidget *centralWidget;
  QGridLayout *gridLayout;
  QLineEdit *fileEdit;
  QLabel *label;
  QPushButton *stopButton;
  QPushButton *fileBrowseButton;
  QPushButton *directoryBrowseButton;
  QLineEdit *patternEdit;
  QLabel *label_3;
  QPushButton *searchButton;
  QLabel *label_2;
  QListWidget *listWidget;
  QLabel *label_4;
  QTextBrowser *infoBrowser;
  QToolBar *mainToolBar;
  QStatusBar *statusBar;
  QToolBar *toolBar;

  void setupUi(QMainWindow *grep)
  {
    if (grep->objectName().isEmpty())
      grep->setObjectName(QStringLiteral("grep"));
    grep->resize(840, 565);
    centralWidget = new QWidget(grep);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    fileEdit = new QLineEdit(centralWidget);
    fileEdit->setObjectName(QStringLiteral("fileEdit"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(fileEdit->sizePolicy().hasHeightForWidth());
    fileEdit->setSizePolicy(sizePolicy);

    gridLayout->addWidget(fileEdit, 1, 0, 1, 1);

    label = new QLabel(centralWidget);
    label->setObjectName(QStringLiteral("label"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy1);

    gridLayout->addWidget(label, 8, 0, 1, 1);

    stopButton = new QPushButton(centralWidget);
    stopButton->setObjectName(QStringLiteral("stopButton"));
    QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
    stopButton->setSizePolicy(sizePolicy2);

    gridLayout->addWidget(stopButton, 3, 1, 1, 1);

    fileBrowseButton = new QPushButton(centralWidget);
    fileBrowseButton->setObjectName(QStringLiteral("fileBrowseButton"));
    sizePolicy2.setHeightForWidth(fileBrowseButton->sizePolicy().hasHeightForWidth());
    fileBrowseButton->setSizePolicy(sizePolicy2);

    gridLayout->addWidget(fileBrowseButton, 3, 0, 1, 1);

    directoryBrowseButton = new QPushButton(centralWidget);
    directoryBrowseButton->setObjectName(QStringLiteral("directoryBrowseButton"));
    sizePolicy2.setHeightForWidth(directoryBrowseButton->sizePolicy().hasHeightForWidth());
    directoryBrowseButton->setSizePolicy(sizePolicy2);

    gridLayout->addWidget(directoryBrowseButton, 2, 0, 1, 1);

    patternEdit = new QLineEdit(centralWidget);
    patternEdit->setObjectName(QStringLiteral("patternEdit"));
    sizePolicy.setHeightForWidth(patternEdit->sizePolicy().hasHeightForWidth());
    patternEdit->setSizePolicy(sizePolicy);

    gridLayout->addWidget(patternEdit, 1, 1, 1, 1);

    label_3 = new QLabel(centralWidget);
    label_3->setObjectName(QStringLiteral("label_3"));
    sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
    label_3->setSizePolicy(sizePolicy1);

    gridLayout->addWidget(label_3, 4, 0, 1, 1);

    searchButton = new QPushButton(centralWidget);
    searchButton->setObjectName(QStringLiteral("searchButton"));
    sizePolicy2.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
    searchButton->setSizePolicy(sizePolicy2);

    gridLayout->addWidget(searchButton, 2, 1, 1, 1);

    label_2 = new QLabel(centralWidget);
    label_2->setObjectName(QStringLiteral("label_2"));
    sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy1);

    gridLayout->addWidget(label_2, 0, 1, 1, 1);

    listWidget = new QListWidget(centralWidget);
    listWidget->setObjectName(QStringLiteral("listWidget"));

    gridLayout->addWidget(listWidget, 5, 0, 3, 2);

    label_4 = new QLabel(centralWidget);
    label_4->setObjectName(QStringLiteral("label_4"));
    sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
    label_4->setSizePolicy(sizePolicy1);

    gridLayout->addWidget(label_4, 0, 0, 1, 1);

    infoBrowser = new QTextBrowser(centralWidget);
    infoBrowser->setObjectName(QStringLiteral("infoBrowser"));
    sizePolicy.setHeightForWidth(infoBrowser->sizePolicy().hasHeightForWidth());
    infoBrowser->setSizePolicy(sizePolicy);
    infoBrowser->setMaximumSize(QSize(16777215, 16777215));

    gridLayout->addWidget(infoBrowser, 11, 0, 2, 2);

    grep->setCentralWidget(centralWidget);
    mainToolBar = new QToolBar(grep);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    grep->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(grep);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    grep->setStatusBar(statusBar);
    toolBar = new QToolBar(grep);
    toolBar->setObjectName(QStringLiteral("toolBar"));
    grep->addToolBar(Qt::TopToolBarArea, toolBar);

    retranslateUi(grep);

    QMetaObject::connectSlotsByName(grep);
  } // setupUi

  void retranslateUi(QMainWindow *grep)
  {
    grep->setWindowTitle(QApplication::translate("grep", "grep", Q_NULLPTR));
    fileEdit->setText(QString());
    label->setText(QApplication::translate("grep", "Statistics", Q_NULLPTR));
    stopButton->setText(QApplication::translate("grep", "Stop", Q_NULLPTR));
    fileBrowseButton->setText(QApplication::translate("grep", "Select file", Q_NULLPTR));
    directoryBrowseButton->setText(QApplication::translate("grep", "Select directory", Q_NULLPTR));
    label_3->setText(QApplication::translate("grep", "Result", Q_NULLPTR));
    searchButton->setText(QApplication::translate("grep", "Run", Q_NULLPTR));
    label_2->setText(QApplication::translate("grep", "Pattern", Q_NULLPTR));
    label_4->setText(QApplication::translate("grep", "Search in...", Q_NULLPTR));
    toolBar->setWindowTitle(QApplication::translate("grep", "toolBar", Q_NULLPTR));
  } // retranslateUi

};

namespace Ui {
  class grep: public Ui_grep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
