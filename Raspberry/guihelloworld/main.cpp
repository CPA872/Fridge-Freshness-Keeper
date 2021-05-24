#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;

    MainWindow w;
    w.setWindowTitle("Fridge Freshness Keeper");
    w.show();

    w.testTemperatureDisplay();
    w.setDisplayHumidity(45);
    w.initTable();

    return app.exec();
}
