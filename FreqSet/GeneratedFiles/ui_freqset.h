/********************************************************************************
** Form generated from reading UI file 'freqset.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQSET_H
#define UI_FREQSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FreqSetClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_Add;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_Delete;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget_Freqset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FreqSetClass)
    {
        if (FreqSetClass->objectName().isEmpty())
            FreqSetClass->setObjectName(QString::fromUtf8("FreqSetClass"));
        FreqSetClass->resize(1282, 577);
        centralWidget = new QWidget(FreqSetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1030, 140, 101, 20));
        pushButton_Add = new QPushButton(centralWidget);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(1030, 210, 101, 23));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1030, 170, 101, 20));
        pushButton_Delete = new QPushButton(centralWidget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(1030, 250, 101, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1130, 150, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1130, 180, 54, 12));
        listWidget_Freqset = new QListWidget(centralWidget);
        listWidget_Freqset->setObjectName(QString::fromUtf8("listWidget_Freqset"));
        listWidget_Freqset->setGeometry(QRect(770, 140, 256, 381));
        FreqSetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FreqSetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1282, 23));
        FreqSetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FreqSetClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FreqSetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FreqSetClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FreqSetClass->setStatusBar(statusBar);

        retranslateUi(FreqSetClass);

        QMetaObject::connectSlotsByName(FreqSetClass);
    } // setupUi

    void retranslateUi(QMainWindow *FreqSetClass)
    {
        FreqSetClass->setWindowTitle(QApplication::translate("FreqSetClass", "FreqSet", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("FreqSetClass", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("FreqSetClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FreqSetClass", "MHz", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FreqSetClass", "dB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FreqSetClass: public Ui_FreqSetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQSET_H
