#ifndef MAINWINDOW_H
#define MAINWINDOW_H

constexpr int NAME_COL = 0;
constexpr int COUNT_COL = 1;
constexpr int SHELF_LIFE_COL = 2;

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "newitemwindow.h"
#include "globals.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void testTemperatureDisplay();

    void setDisplayTemperature(float temp);

    void setDisplayHumidity(float humidity);

    void initTable();

    void testTable();

    void setTableRow(int row, QString name, int count, int shelfLife);

    void setTableRow(int row, FoodItem* item);

    void addTableRow(FoodItem* newItem);

    void inspectFoodList();

    std::string trim(const std::string& str, const std::string& whitespace = " \t");


private slots:
    void on_addButton_clicked();

    void on_minusButton_clicked();

    void on_deleteButton_clicked();

    void on_manualAdd_clicked();

    void receiveNewItem(FoodItem* newItem);

    void updateTime();

    void on_refreshButton_clicked();

    void on_dateDisplay_dateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    std::vector<FoodItem*> foodList;
    QTimer* timer_1min;
    int updateFlag;
    NewItemWindow* addWindow;

    const int UPDATE_INTERVAL = 15;
    const int REFRESH_INTERVAL = 90;

    void setRowColor();

};


#endif // MAINWINDOW_H
