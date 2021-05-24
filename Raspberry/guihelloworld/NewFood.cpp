#include "NewFood.h"
#include "ui_NewFood.h"

NewFood::NewFood(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewFood)
{
    ui->setupUi(this);
}
