#include "newitemwindow.h"
#include "ui_newitemwindow.h"

NewItemWindow::NewItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewItemWindow)
{
    ui->setupUi(this);
}

NewItemWindow::~NewItemWindow()
{
    delete ui;
}

void NewItemWindow::initUI() {
    ui->nameBox->setText(QString(""));
    ui->countBox->setValue(1);
    ui->purchaseDateEdit->setDate(QDate::currentDate());
    ui->shelfLifeBox->setValue(7);
    ui->expirationDateEdit->setDate(QDate::currentDate().addDays(ui->shelfLifeBox->value()));
}

// The below two functions are for syncing shelf life and expiration date
void NewItemWindow::on_shelfLifeBox_editingFinished()
{
    ui->expirationDateEdit->setDate(ui->purchaseDateEdit->date().addDays(ui->shelfLifeBox->value()));
}

void NewItemWindow::on_shelfLifeBox_valueChanged(int arg1)
{
    ui->expirationDateEdit->setDate(ui->purchaseDateEdit->date().addDays(ui->shelfLifeBox->value()));
}

void NewItemWindow::on_expirationDateEdit_dateChanged(const QDate &date)
{
    ui->shelfLifeBox->setValue(ui->purchaseDateEdit->date().daysTo(ui->expirationDateEdit->date()));
}

void NewItemWindow::on_cancelButton_clicked()
{
    this->close();
}

// MainWindow performs signal connecting and get string of data
void NewItemWindow::on_confirmButton_clicked()
{
    if (ui->nameBox->text().length() == 0) {
        QMessageBox::warning(
            this,
            tr("Warning"),
            tr("Name cannot be empty") );
        return;
    }

    FoodItem* newItem = new FoodItem;
    newItem->name         = ui->nameBox->text();
    newItem->count        = ui->countBox->value();
    newItem->shelfLife    = ui->shelfLifeBox->value();

    this->close();

    emit sendNewItem(newItem);
}

void NewItemWindow::on_countAddButton_clicked()
{
    ui->countBox->setValue(ui->countBox->value() + 1);
}

void NewItemWindow::on_countMinusButton_clicked()
{
    ui->countBox->setValue(ui->countBox->value() - 1);
}

void NewItemWindow::on_shelfLifeAddbutton_clicked()
{
    ui->shelfLifeBox->setValue(ui->shelfLifeBox->value() + 1);
}

void NewItemWindow::on_shelfLifeMinusButton_clicked()
{
    ui->shelfLifeBox->setValue(ui->shelfLifeBox->value() - 1);
}
