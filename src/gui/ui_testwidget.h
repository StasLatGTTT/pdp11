/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QPushButton *buttonStart;
    QPushButton *buttonRestart;
    QTableView *tableView;
    QTableView *tableView_2;
    QLabel *label;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_3;
    QGraphicsView *graphicsView;
    QLabel *label_4;
    QPushButton *buttonStep;
    QTableView *tableView_3;
    QLabel *label_5;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QString::fromUtf8("TestWidget"));
        TestWidget->resize(635, 379);
        buttonStart = new QPushButton(TestWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(10, 10, 161, 27));
        buttonRestart = new QPushButton(TestWidget);
        buttonRestart->setObjectName(QString::fromUtf8("buttonRestart"));
        buttonRestart->setGeometry(QRect(10, 40, 161, 27));
        tableView = new QTableView(TestWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 120, 161, 161));
        tableView_2 = new QTableView(TestWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(190, 40, 111, 311));
        label = new QLabel(TestWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 100, 67, 17));
        label_2 = new QLabel(TestWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 10, 101, 17));
        scrollArea = new QScrollArea(TestWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(320, 40, 101, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 99, 309));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_3 = new QLabel(TestWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 10, 81, 20));
        graphicsView = new QGraphicsView(TestWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(440, 120, 181, 161));
        label_4 = new QLabel(TestWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 80, 67, 17));
        buttonStep = new QPushButton(TestWidget);
        buttonStep->setObjectName(QString::fromUtf8("buttonStep"));
        buttonStep->setGeometry(QRect(8, 70, 161, 27));
        tableView_3 = new QTableView(TestWidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(10, 320, 161, 31));
        label_5 = new QLabel(TestWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 290, 91, 20));

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "Form", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("TestWidget", "Start || Stop", 0, QApplication::UnicodeUTF8));
        buttonRestart->setText(QApplication::translate("TestWidget", "Restart", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestWidget", "Registers", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TestWidget", "Disassembler", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TestWidget", "Instructions", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TestWidget", "Logo", 0, QApplication::UnicodeUTF8));
        buttonStep->setText(QApplication::translate("TestWidget", "Step", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TestWidget", "Status word", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
