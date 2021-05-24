#ifndef NEWITEMWINDOW_H
#define NEWITEMWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>

#include "globals.h"

namespace Ui {
class NewItemWindow;
}

class NewItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewItemWindow(QWidget *parent = nullptr);
    ~NewItemWindow();

    void initUI();

private slots:
    void on_shelfLifeBox_editingFinished();

    void on_shelfLifeBox_valueChanged(int arg1);

    void on_expirationDateEdit_dateChanged(const QDate &date);

    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

    void on_countAddButton_clicked();

    void on_countMinusButton_clicked();

    void on_shelfLifeAddbutton_clicked();

    void on_shelfLifeMinusButton_clicked();

private:
    Ui::NewItemWindow *ui;

signals:
    void sendNewItem(FoodItem* newItem);
};

#endif // NEWITEMWINDOW_H
