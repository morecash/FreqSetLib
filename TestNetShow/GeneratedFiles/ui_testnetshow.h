/********************************************************************************
** Form generated from reading UI file 'testnetshow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTNETSHOW_H
#define UI_TESTNETSHOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestNetShowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestNetShowClass)
    {
        if (TestNetShowClass->objectName().isEmpty())
            TestNetShowClass->setObjectName(QString::fromUtf8("TestNetShowClass"));
        TestNetShowClass->resize(600, 400);
        menuBar = new QMenuBar(TestNetShowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TestNetShowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestNetShowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestNetShowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestNetShowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestNetShowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestNetShowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestNetShowClass->setStatusBar(statusBar);

        retranslateUi(TestNetShowClass);

        QMetaObject::connectSlotsByName(TestNetShowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestNetShowClass)
    {
        TestNetShowClass->setWindowTitle(QApplication::translate("TestNetShowClass", "TestNetShow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestNetShowClass: public Ui_TestNetShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTNETSHOW_H
