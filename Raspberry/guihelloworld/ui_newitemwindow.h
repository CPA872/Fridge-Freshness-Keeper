/********************************************************************************
** Form generated from reading UI file 'newitemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWITEMWINDOW_H
#define UI_NEWITEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewItemWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *nameBox;
    QSpinBox *countBox;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *shelfLifeBox;
    QDateEdit *purchaseDateEdit;
    QPushButton *confirmButton;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *cancelButton;
    QDateEdit *expirationDateEdit;
    QPushButton *shelfLifeMinusButton;
    QPushButton *countMinusButton;
    QPushButton *countAddButton;
    QPushButton *shelfLifeAddbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewItemWindow)
    {
        if (NewItemWindow->objectName().isEmpty())
            NewItemWindow->setObjectName(QString::fromUtf8("NewItemWindow"));
        NewItemWindow->resize(701, 409);
        centralwidget = new QWidget(NewItemWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nameBox = new QLineEdit(centralwidget);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));
        nameBox->setGeometry(QRect(222, 11, 291, 50));
        QFont font;
        font.setPointSize(15);
        nameBox->setFont(font);
        countBox = new QSpinBox(centralwidget);
        countBox->setObjectName(QString::fromUtf8("countBox"));
        countBox->setGeometry(QRect(222, 69, 141, 50));
        countBox->setFont(font);
        countBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(102, 194, 111, 31));
        label->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(134, 20, 81, 31));
        label_3->setFont(font);
        shelfLifeBox = new QSpinBox(centralwidget);
        shelfLifeBox->setObjectName(QString::fromUtf8("shelfLifeBox"));
        shelfLifeBox->setGeometry(QRect(222, 184, 141, 50));
        shelfLifeBox->setFont(font);
        shelfLifeBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shelfLifeBox->setMaximum(999);
        purchaseDateEdit = new QDateEdit(centralwidget);
        purchaseDateEdit->setObjectName(QString::fromUtf8("purchaseDateEdit"));
        purchaseDateEdit->setGeometry(QRect(222, 126, 141, 50));
        purchaseDateEdit->setFont(font);
        purchaseDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        purchaseDateEdit->setCurrentSection(QDateTimeEdit::MonthSection);
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(518, 240, 131, 51));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        confirmButton->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(81, 134, 131, 31));
        label_2->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(132, 80, 81, 31));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 249, 161, 31));
        label_5->setFont(font);
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(380, 240, 131, 51));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        cancelButton->setFont(font2);
        expirationDateEdit = new QDateEdit(centralwidget);
        expirationDateEdit->setObjectName(QString::fromUtf8("expirationDateEdit"));
        expirationDateEdit->setGeometry(QRect(222, 241, 141, 50));
        expirationDateEdit->setFont(font);
        expirationDateEdit->setCurrentSection(QDateTimeEdit::MonthSection);
        shelfLifeMinusButton = new QPushButton(centralwidget);
        shelfLifeMinusButton->setObjectName(QString::fromUtf8("shelfLifeMinusButton"));
        shelfLifeMinusButton->setGeometry(QRect(450, 183, 50, 50));
        QFont font3;
        font3.setPointSize(29);
        shelfLifeMinusButton->setFont(font3);
        countMinusButton = new QPushButton(centralwidget);
        countMinusButton->setObjectName(QString::fromUtf8("countMinusButton"));
        countMinusButton->setGeometry(QRect(450, 70, 50, 50));
        countMinusButton->setFont(font3);
        countAddButton = new QPushButton(centralwidget);
        countAddButton->setObjectName(QString::fromUtf8("countAddButton"));
        countAddButton->setGeometry(QRect(380, 70, 50, 50));
        countAddButton->setFont(font3);
        shelfLifeAddbutton = new QPushButton(centralwidget);
        shelfLifeAddbutton->setObjectName(QString::fromUtf8("shelfLifeAddbutton"));
        shelfLifeAddbutton->setGeometry(QRect(380, 184, 50, 50));
        shelfLifeAddbutton->setFont(font3);
        NewItemWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewItemWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 701, 22));
        NewItemWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(NewItemWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewItemWindow->setStatusBar(statusbar);

        retranslateUi(NewItemWindow);

        QMetaObject::connectSlotsByName(NewItemWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NewItemWindow)
    {
        NewItemWindow->setWindowTitle(QApplication::translate("NewItemWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("NewItemWindow", "Shelf Life", nullptr));
        label_3->setText(QApplication::translate("NewItemWindow", "Name", nullptr));
        purchaseDateEdit->setDisplayFormat(QApplication::translate("NewItemWindow", "M/d/yyyy", nullptr));
        confirmButton->setText(QApplication::translate("NewItemWindow", "CONFIRM", nullptr));
        label_2->setText(QApplication::translate("NewItemWindow", "Date Added", nullptr));
        label_4->setText(QApplication::translate("NewItemWindow", "Count", nullptr));
        label_5->setText(QApplication::translate("NewItemWindow", "Expiration Date", nullptr));
        cancelButton->setText(QApplication::translate("NewItemWindow", "Cancel", nullptr));
        expirationDateEdit->setDisplayFormat(QApplication::translate("NewItemWindow", "M/d/yyyy", nullptr));
        shelfLifeMinusButton->setText(QApplication::translate("NewItemWindow", "-", nullptr));
        countMinusButton->setText(QApplication::translate("NewItemWindow", "-", nullptr));
        countAddButton->setText(QApplication::translate("NewItemWindow", "+", nullptr));
        shelfLifeAddbutton->setText(QApplication::translate("NewItemWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewItemWindow: public Ui_NewItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWITEMWINDOW_H
