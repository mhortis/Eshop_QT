#include "neworder.h"
#include "ui_neworder.h"

NewOrder::NewOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOrder)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void NewOrder::setOrder(Order order){
    this->order = order;
}

void NewOrder::showOrder(){
    ui->table->setColumnCount(6);
    ui->table->setRowCount(order.getOrderItems().size());
    ui->table->setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price; Quantity").split(";"));
    int row = 0;
    double totalCost = 0;
    for(map<ProductBase, int>::iterator iter = order.getOrderItems().begin(); iter != order.getOrderItems().end(); iter++){
        ProductBase curProduct = iter->first;
        int quantity = iter->second;
        ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(curProduct.getModel())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(curProduct.getManufacturer())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(curProduct.getPhotoUrl())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(curProduct.getDescription())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::number(curProduct.getPrice())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(quantity)));

        totalCost += quantity * curProduct.getPrice();
        row++;
    }
    if(order.getOrderBuyer().getType() == 2){
        UserDAO userDAO(m_db);
        Company company = userDAO.fetchCompanyDetailsFromDB(order.getOrderBuyer().getUserID());
        totalCost *= (1-company.getDiscount());
    }

    ui->totalCostLabel->setText(QString::number(totalCost));
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();

}

NewOrder::~NewOrder()
{
    delete ui;
}
