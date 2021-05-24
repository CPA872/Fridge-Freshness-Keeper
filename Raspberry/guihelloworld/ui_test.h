/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *manualAdd;
    QPushButton *cameraAdd;
    QListWidget *foodList;
    QLabel *label;
    QLCDNumber *temperatureDisplay;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        manualAdd = new QPushButton(centralwidget);
        manualAdd->setObjectName(QString::fromUtf8("manualAdd"));
        manualAdd->setGeometry(QRect(380, 40, 191, 161));
        cameraAdd = new QPushButton(centralwidget);
        cameraAdd->setObjectName(QString::fromUtf8("cameraAdd"));
        cameraAdd->setGeometry(QRect(590, 40, 191, 161));
        foodList = new QListWidget(centralwidget);
        foodList->setObjectName(QString::fromUtf8("foodList"));
        foodList->setGeometry(QRect(10, 40, 351, 481));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 0, 461, 31));
        temperatureDisplay = new QLCDNumber(centralwidget);
        temperatureDisplay->setObjectName(QString::fromUtf8("temperatureDisplay"));
        temperatureDisplay->setGeometry(QRect(400, 320, 141, 71));
        temperatureDisplay->setProperty("intValue", QVariant(-5));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 390, 101, 31));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(590, 320, 191, 71));
        progressBar->setValue(85);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(650, 400, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 260, 121, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        manualAdd->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        cameraAdd->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "                                        Fridge-Freshness-Keeper", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Current Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
