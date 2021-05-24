/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *manualAdd;
    QLCDNumber *temperatureDisplay;
    QLabel *label_2;
    QProgressBar *humidityDisplay;
    QLabel *label_3;
    QTableWidget *foodTable;
    QPushButton *addButton;
    QPushButton *minusButton;
    QPushButton *deleteButton;
    QPushButton *refreshButton;
    QTimeEdit *timeDisplay;
    QDateEdit *dateDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(996, 548);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        manualAdd = new QPushButton(centralwidget);
        manualAdd->setObjectName(QString::fromUtf8("manualAdd"));
        manualAdd->setGeometry(QRect(700, 20, 261, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        manualAdd->setFont(font);
        temperatureDisplay = new QLCDNumber(centralwidget);
        temperatureDisplay->setObjectName(QString::fromUtf8("temperatureDisplay"));
        temperatureDisplay->setGeometry(QRect(700, 240, 111, 71));
        QFont font1;
        font1.setPointSize(8);
        temperatureDisplay->setFont(font1);
        temperatureDisplay->setLayoutDirection(Qt::LeftToRight);
        temperatureDisplay->setSmallDecimalPoint(true);
        temperatureDisplay->setDigitCount(3);
        temperatureDisplay->setSegmentStyle(QLCDNumber::Flat);
        temperatureDisplay->setProperty("value", QVariant(25.000000000000000));
        temperatureDisplay->setProperty("intValue", QVariant(25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(695, 310, 131, 31));
        QFont font2;
        font2.setPointSize(15);
        label_2->setFont(font2);
        humidityDisplay = new QProgressBar(centralwidget);
        humidityDisplay->setObjectName(QString::fromUtf8("humidityDisplay"));
        humidityDisplay->setGeometry(QRect(840, 240, 121, 71));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(false);
        font3.setStyleStrategy(QFont::PreferDefault);
        humidityDisplay->setFont(font3);
        humidityDisplay->setValue(50);
        humidityDisplay->setTextVisible(true);
        humidityDisplay->setTextDirection(QProgressBar::TopToBottom);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(855, 310, 91, 31));
        label_3->setFont(font2);
        foodTable = new QTableWidget(centralwidget);
        foodTable->setObjectName(QString::fromUtf8("foodTable"));
        foodTable->setGeometry(QRect(20, 20, 651, 421));
        foodTable->setFont(font2);
        foodTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        foodTable->setSortingEnabled(true);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(220, 450, 51, 51));
        QFont font4;
        font4.setPointSize(35);
        addButton->setFont(font4);
        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(290, 450, 51, 51));
        minusButton->setFont(font4);
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(360, 450, 51, 51));
        QFont font5;
        font5.setPointSize(26);
        deleteButton->setFont(font5);
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(430, 450, 51, 51));
        QFont font6;
        font6.setPointSize(28);
        refreshButton->setFont(font6);
        timeDisplay = new QTimeEdit(centralwidget);
        timeDisplay->setObjectName(QString::fromUtf8("timeDisplay"));
        timeDisplay->setGeometry(QRect(840, 170, 131, 31));
        QFont font7;
        font7.setPointSize(19);
        timeDisplay->setFont(font7);
        timeDisplay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateDisplay = new QDateEdit(centralwidget);
        dateDisplay->setObjectName(QString::fromUtf8("dateDisplay"));
        dateDisplay->setGeometry(QRect(700, 170, 141, 31));
        dateDisplay->setFont(font7);
        dateDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateDisplay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateDisplay->setDateTime(QDateTime(QDate(2000, 12, 21), QTime(0, 0, 0)));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 996, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        manualAdd->setText(QCoreApplication::translate("MainWindow", "NEW ITEM", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        dateDisplay->setDisplayFormat(QCoreApplication::translate("MainWindow", "M/d/yyyy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
