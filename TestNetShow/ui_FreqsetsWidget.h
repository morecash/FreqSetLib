<<<<<<< HEAD
/********************************************************************************
** Form generated from reading UI file 'FreqsetsWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQSETSWIDGET_H
#define UI_FREQSETSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FreqsetsWidget
{
public:
    QLabel *label;
    QPushButton *pushButton_Add;
    QLineEdit *lineEdit_Freq;
    QPushButton *pushButton_Delete;
    QTableWidget *tableWidget_Freqset;
    QLabel *label_2;
    QTableWidget *tableWidget_AllFreq;
    QPushButton *pushButton_InTable;

    void setupUi(QWidget *FreqsetsWidget)
    {
        if (FreqsetsWidget->objectName().isEmpty())
            FreqsetsWidget->setObjectName(QString::fromUtf8("FreqsetsWidget"));
        FreqsetsWidget->resize(1242, 578);
        label = new QLabel(FreqsetsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1210, 450, 31, 20));
        pushButton_Add = new QPushButton(FreqsetsWidget);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(1070, 510, 171, 23));
        lineEdit_Freq = new QLineEdit(FreqsetsWidget);
        lineEdit_Freq->setObjectName(QString::fromUtf8("lineEdit_Freq"));
        lineEdit_Freq->setGeometry(QRect(1100, 450, 111, 20));
        pushButton_Delete = new QPushButton(FreqsetsWidget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(1070, 480, 171, 23));
        tableWidget_Freqset = new QTableWidget(FreqsetsWidget);
        tableWidget_Freqset->setObjectName(QString::fromUtf8("tableWidget_Freqset"));
        tableWidget_Freqset->setGeometry(QRect(1070, 0, 171, 441));
        label_2 = new QLabel(FreqsetsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1070, 450, 31, 16));
        tableWidget_AllFreq = new QTableWidget(FreqsetsWidget);
        tableWidget_AllFreq->setObjectName(QString::fromUtf8("tableWidget_AllFreq"));
        tableWidget_AllFreq->setGeometry(QRect(100, 361, 961, 201));
        pushButton_InTable = new QPushButton(FreqsetsWidget);
        pushButton_InTable->setObjectName(QString::fromUtf8("pushButton_InTable"));
        pushButton_InTable->setGeometry(QRect(1070, 540, 171, 23));

        retranslateUi(FreqsetsWidget);

        QMetaObject::connectSlotsByName(FreqsetsWidget);
    } // setupUi

    void retranslateUi(QWidget *FreqsetsWidget)
    {
        FreqsetsWidget->setWindowTitle(QApplication::translate("FreqsetsWidget", "FreqsetsWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FreqsetsWidget", " MHz", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("FreqsetsWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("FreqsetsWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FreqsetsWidget", " \351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        pushButton_InTable->setText(QApplication::translate("FreqsetsWidget", "\345\205\245\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FreqsetsWidget: public Ui_FreqsetsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQSETSWIDGET_H
=======
/********************************************************************************
** Form generated from reading UI file 'FreqsetsWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQSETSWIDGET_H
#define UI_FREQSETSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FreqsetsWidget
{
public:
    QLabel *label;
    QPushButton *pushButton_Add;
    QLineEdit *lineEdit_Freq;
    QPushButton *pushButton_Delete;
    QTableWidget *tableWidget_Freqset;
    QLabel *label_2;
    QTableWidget *tableWidget_AllFreq;
    QPushButton *pushButton_InTable;

    void setupUi(QWidget *FreqsetsWidget)
    {
        if (FreqsetsWidget->objectName().isEmpty())
            FreqsetsWidget->setObjectName(QString::fromUtf8("FreqsetsWidget"));
        FreqsetsWidget->resize(1242, 578);
        label = new QLabel(FreqsetsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1210, 450, 31, 20));
        pushButton_Add = new QPushButton(FreqsetsWidget);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(1070, 510, 171, 23));
        lineEdit_Freq = new QLineEdit(FreqsetsWidget);
        lineEdit_Freq->setObjectName(QString::fromUtf8("lineEdit_Freq"));
        lineEdit_Freq->setGeometry(QRect(1100, 450, 111, 20));
        pushButton_Delete = new QPushButton(FreqsetsWidget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(1070, 480, 171, 23));
        tableWidget_Freqset = new QTableWidget(FreqsetsWidget);
        tableWidget_Freqset->setObjectName(QString::fromUtf8("tableWidget_Freqset"));
        tableWidget_Freqset->setGeometry(QRect(1070, 0, 171, 441));
        label_2 = new QLabel(FreqsetsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1070, 450, 31, 16));
        tableWidget_AllFreq = new QTableWidget(FreqsetsWidget);
        tableWidget_AllFreq->setObjectName(QString::fromUtf8("tableWidget_AllFreq"));
        tableWidget_AllFreq->setGeometry(QRect(100, 361, 961, 201));
        pushButton_InTable = new QPushButton(FreqsetsWidget);
        pushButton_InTable->setObjectName(QString::fromUtf8("pushButton_InTable"));
        pushButton_InTable->setGeometry(QRect(1070, 540, 171, 23));

        retranslateUi(FreqsetsWidget);

        QMetaObject::connectSlotsByName(FreqsetsWidget);
    } // setupUi

    void retranslateUi(QWidget *FreqsetsWidget)
    {
        FreqsetsWidget->setWindowTitle(QApplication::translate("FreqsetsWidget", "FreqsetsWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FreqsetsWidget", " MHz", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("FreqsetsWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_Delete->setText(QApplication::translate("FreqsetsWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FreqsetsWidget", " \351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        pushButton_InTable->setText(QApplication::translate("FreqsetsWidget", "\345\205\245\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FreqsetsWidget: public Ui_FreqsetsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQSETSWIDGET_H
>>>>>>> origin/master
