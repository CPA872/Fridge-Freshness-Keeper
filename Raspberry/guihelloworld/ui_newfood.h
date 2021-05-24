/********************************************************************************
** Form generated from reading UI file 'newfood.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFOOD_H
#define UI_NEWFOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QDateEdit *purchaseDateEdit;
    QSpinBox *shelfLifeBox;
    QPushButton *cancelButton;
    QPushButton *confirmButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nameBox;
    QLabel *label_3;
    QLabel *label_4;
    QDateEdit *purchaseDateEdit_2;
    QLabel *label_5;
    QSpinBox *spinBox;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(470, 225);
        purchaseDateEdit = new QDateEdit(Form);
        purchaseDateEdit->setObjectName(QString::fromUtf8("purchaseDateEdit"));
        purchaseDateEdit->setGeometry(QRect(170, 80, 110, 26));
        shelfLifeBox = new QSpinBox(Form);
        shelfLifeBox->setObjectName(QString::fromUtf8("shelfLifeBox"));
        shelfLifeBox->setGeometry(QRect(170, 110, 44, 26));
        cancelButton = new QPushButton(Form);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(240, 185, 89, 25));
        confirmButton = new QPushButton(Form);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(350, 185, 89, 25));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(96, 113, 67, 17));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(62, 86, 101, 17));
        nameBox = new QLineEdit(Form);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));
        nameBox->setGeometry(QRect(170, 11, 113, 25));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 16, 41, 20));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 50, 41, 20));
        purchaseDateEdit_2 = new QDateEdit(Form);
        purchaseDateEdit_2->setObjectName(QString::fromUtf8("purchaseDateEdit_2"));
        purchaseDateEdit_2->setGeometry(QRect(168, 144, 110, 26));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(52, 148, 111, 20));
        spinBox = new QSpinBox(Form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(170, 47, 44, 26));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        cancelButton->setText(QApplication::translate("Form", "Cancel", nullptr));
        confirmButton->setText(QApplication::translate("Form", "CONFIRM", nullptr));
        label->setText(QApplication::translate("Form", "Shelf Life", nullptr));
        label_2->setText(QApplication::translate("Form", "Purchase Date", nullptr));
        label_3->setText(QApplication::translate("Form", "Name", nullptr));
        label_4->setText(QApplication::translate("Form", "Count", nullptr));
        label_5->setText(QApplication::translate("Form", "Expiration Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFOOD_H
