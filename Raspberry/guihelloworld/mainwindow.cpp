#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->addWindow = new NewItemWindow(this);
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    QObject::connect(addWindow, &NewItemWindow::sendNewItem, this, &MainWindow::receiveNewItem);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    this->updateFlag = this->UPDATE_INTERVAL;
}

void MainWindow::testTemperatureDisplay() {
    ui->temperatureDisplay->display(50);
}

void MainWindow::setDisplayTemperature(float temp) {
    ui->temperatureDisplay->display(temp);
}

void MainWindow::setDisplayHumidity(float humidity) {
    ui->humidityDisplay->setValue(humidity);
}

// Function to initialize foodTable
void MainWindow::initTable() {
    ui->foodTable->setColumnCount(3);
    ui->foodTable->setRowCount(0);
    ui->foodTable->setShowGrid(true);
    ui->foodTable->setAlternatingRowColors(true);
    QStringList labels;
    labels << "Name" << "Count" << "Shelf Life";

    // set column width to fill in the entire table panel
    ui->foodTable->setHorizontalHeaderLabels(labels);
    ui->foodTable->setColumnWidth(NAME_COL, 430);
    ui->foodTable->setColumnWidth(COUNT_COL, 80);
    ui->foodTable->setColumnWidth(SHELF_LIFE_COL, 110);
}

void MainWindow::testTable() {
    this->setTableRow(0, "Apples a very loooooooooooooooooong ", 12, 7);
    this->setTableRow(1, "Bpples", 2, 7);
    this->setTableRow(2, "Cpples", 9, 7);
    this->setTableRow(3, "Dpples", 8, 7);
    this->setTableRow(4, "Epples", 7, 7);
    this->setTableRow(5, "Fpples", 6, 7);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTableRow(int row, QString name, int count, int shelfLife) {
    ui->foodTable->setItem(row, NAME_COL, new QTableWidgetItem(name));

    QTableWidgetItem* newCountItem = new QTableWidgetItem;
    newCountItem->setData(Qt::EditRole, count);
    ui->foodTable->setItem(row, COUNT_COL, newCountItem);

    QTableWidgetItem* newShelfLifeItem = new QTableWidgetItem;
    newShelfLifeItem->setData(Qt::EditRole, shelfLife);
    ui->foodTable->setItem(row, SHELF_LIFE_COL, newShelfLifeItem);
}

void MainWindow::setTableRow(int row, FoodItem *item) {
    this->setTableRow(row, item->name, item->count, item->shelfLife);
}

void MainWindow::addTableRow(FoodItem *newItem) {
    ui->foodTable->insertRow(ui->foodTable->rowCount());  // inserts a row
    this->setTableRow(ui->foodTable->rowCount() - 1, newItem->name, newItem->count, newItem->shelfLife);
}

// click function for addButton, add 1 to the count field
void MainWindow::on_addButton_clicked()
{
    int selectedRow = ui->foodTable->currentRow();
    if (selectedRow == -1) {  // exit if nothing is selected
        return;
    }

    QTableWidgetItem* item = ui->foodTable->item(selectedRow, COUNT_COL);
    if (item == nullptr) {  // selecting an empty line
        return;
    }

    int newCount = item->text().toInt() + 1;
    ui->foodTable->setItem(selectedRow, COUNT_COL, new QTableWidgetItem(QString::number(newCount)));

}

// click function for addButton, minus 1 to the count field
void MainWindow::on_minusButton_clicked()
{
    int selectedRow = ui->foodTable->currentRow();
    if (selectedRow == -1) {  // exit if nothing is selected
        return;
    }

    QTableWidgetItem* item = ui->foodTable->item(selectedRow, COUNT_COL);
    if (item == nullptr) {
        return;
    }

    int newCount = item->text().toInt() - 1;
    ui->foodTable->setItem(selectedRow, COUNT_COL, new QTableWidgetItem(QString::number(newCount)));

    if (newCount == 0) {
        ui->foodTable->removeRow(selectedRow);
    }
}

void MainWindow::on_deleteButton_clicked()
{
    int selectedRow = ui->foodTable->currentRow();
    if (selectedRow == -1) {  // exit if nothing is selected
        return;
    }

    ui->foodTable->removeRow(selectedRow);
}

void MainWindow::on_manualAdd_clicked()
{
    addWindow->setWindowTitle("Add a new item");
    addWindow->initUI();  // set UI to default everytime
    addWindow->setGeometry(0, 0, addWindow->width(), addWindow->height());
    addWindow->show();
}

void MainWindow::receiveNewItem(FoodItem* newItem) {
    qDebug() << "MainWindow::receiveNewItem called";
    if (newItem != nullptr) {
        qDebug() << newItem->name;
    }
    this->addTableRow(newItem);
    this->foodList.push_back(newItem);
}

void MainWindow::updateTime() {
    ui->timeDisplay->setTime(QTime::currentTime());
    ui->dateDisplay->setDate(QDate::currentDate());

    if (this->updateFlag % this->UPDATE_INTERVAL == 0) {
        this->updateFlag = 1;

        try {
            std::fstream file;
//            file.open("/home/cx872/dht_readings.txt");
            file.open("/home/pi/dht_readings.txt");

            float temperature;
            int   humidity;

            file >> humidity >> temperature;
            file.close();

            qDebug() << this->updateFlag << "temp, hum: " << temperature << " " << humidity;

            ui->temperatureDisplay->display(temperature);
            ui->humidityDisplay->setValue(humidity);
        } catch (std::exception e) {
            qDebug() << e.what();
        }

        try {
            this->on_refreshButton_clicked();
        } catch (std::exception e) {
            qDebug() << e.what();
        }

    } else {
        this->updateFlag++;
    }


    this->setRowColor();

}

void MainWindow::inspectFoodList() {
    for (auto food : foodList) {
        qDebug() << food->name << " " << food->count << food->shelfLife;
    }
}

std::string trim(const std::string& str, const std::string& whitespace = " \t") {
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos)
            return ""; // no content

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
}

void MainWindow::on_refreshButton_clicked()
{
    qDebug() << "[INFO] refresh operation";
    inspectFoodList();
    std::fstream outFile;
    outFile.open("ffk_food_list.txt", std::ios::out);

    for (int i = 0; i < ui->foodTable->rowCount(); i++) {
        auto rowName = ui->foodTable->item(i, NAME_COL);
        auto rowCount = ui->foodTable->item(i, COUNT_COL);
        auto rowShelfLife = ui->foodTable->item(i, SHELF_LIFE_COL);

        outFile << rowName->data(Qt::DisplayRole).toString().toStdString() << ", ";
        outFile << rowCount->data(Qt::DisplayRole).toInt() << ", ";
        outFile << rowShelfLife->data(Qt::DisplayRole).toInt() << "\n";
    }

    outFile.close();
    qDebug() << "Written current list to file";

    system("python3 dynamo.py");

    // update current list through the update_foodlist.txt file generated from dynamo.py
    // first, clear current table and foodList
    while(ui->foodTable->rowCount() > 0) {
        ui->foodTable->removeRow(0);
    }
    this->foodList.clear();

    try {
        std::fstream inFile;
//        inFile.open("update_foodlist.txt");
        inFile.open("/home/pi/update_foodlist.txt");

        std::string line;

        while (std::getline(inFile, line))
        {
            std::istringstream iss(line);
            std::string name;
            std::string count, shelfLife;

            std::getline(iss, name, ',');
            std::getline(iss, count, ',');
            std::getline(iss, shelfLife, ',');
//            iss >> name >> count >> shelfLife;
            qDebug() << name.c_str() << " " << count.c_str() << " " << shelfLife.c_str();
            qDebug() << "count: " << count.c_str() << ":";
            FoodItem* item = new FoodItem;
            item->name         = QString::fromStdString(name);
            item->count        = std::stoi(count);
            item->shelfLife    = std::stoi(shelfLife);
            this->foodList.push_back(item);
        }
        inFile.close();

        for (auto item : this->foodList) {
            this->addTableRow(item);
        }

    } catch (std::exception e) {
        qDebug() << e.what();
    }

    this->setRowColor();
}

void MainWindow::on_dateDisplay_dateChanged(const QDate &date)
{
    qDebug() << "update shelf life";

    // iterate through the table to minus every shelf life by 1
    for (int i = 0; i < ui->foodTable->rowCount(); i++) {
        auto rowShelfLife = ui->foodTable->item(i, SHELF_LIFE_COL);
        rowShelfLife->setData(Qt::DisplayRole, rowShelfLife->data(Qt::DisplayRole).toInt() - 1);
    }

    this->setRowColor();
}

void MainWindow::setRowColor() {
    for (int i = 0; i < ui->foodTable->rowCount(); i++) {
        auto rowName = ui->foodTable->item(i, NAME_COL);
        auto rowCount = ui->foodTable->item(i, COUNT_COL);
        auto rowShelfLife = ui->foodTable->item(i, SHELF_LIFE_COL);

        if (rowShelfLife->data(Qt::DisplayRole).toInt() <= 1) {
            rowName->setBackgroundColor(QColor("yellow"));
            rowCount->setBackgroundColor(QColor("yellow"));
            rowShelfLife->setBackgroundColor(QColor("yellow"));
        }
    }
}
