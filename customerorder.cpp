#include "customerorder.h"
#include "ui_customerorder.h"

CustomerOrder::CustomerOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerOrder)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void CustomerOrder::setOrder(Order order){
    this->order = order;
}

void CustomerOrder::showOrderItems(){
    map<ProductBase, int> items = order.getOrderItems();

    ui->table->setColumnCount(6);
    ui->table->setRowCount(items.size());
    ui->table->setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price; Quantity").split(";"));
    int row = 0;

    for(map<ProductBase, int>::iterator iter = items.begin(); iter != items.end(); iter++){
        ProductBase curProduct = iter->first;
        int quantity = iter->second;

        ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(curProduct.getModel())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(curProduct.getManufacturer())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(curProduct.getPhotoUrl())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(curProduct.getDescription())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::number(curProduct.getPrice())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(quantity)));

        row++;
    }

    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();

}

CustomerOrder::~CustomerOrder()
{
    delete ui;
}
