#ifndef NEWFOOD_H
#define NEWFOOD_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class NewFood; }
QT_END_NAMESPACE


class NewFood : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewFood(QWidget *parent = 0);

private:
    Ui::NewFood *ui;

signals:


};

#endif // NEWFOOD_H
