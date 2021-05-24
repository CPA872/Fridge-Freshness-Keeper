#ifndef GLOBALS_H
#define GLOBALS_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

typedef struct {
    QString name;
    int count;
    int shelfLife;
    QDate expirationDate;
} FoodItem;



#endif // GLOBALS_H
