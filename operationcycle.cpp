#include "operationcycle.h"
#include "ui_operationcycle.h"
#include "DBConnection.h"
#include "OrderDAO.h"

operationCycle::operationCycle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operationCycle)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
    //Calculate the Total Revenue of All the orders
    ui->showRevenue->setAlignment(Qt::AlignCenter);
    OrderDAO OrderDAO(m_db);
    totalOrders=OrderDAO.fetchAllOrderCost();
    double total=0;
        for( int i = 0; i != totalOrders.size(); i++) {
            total+= totalOrders[i];
        }
     if(total>0){
        ui->showRevenue->setText(QString::fromStdString("The revenue of the Eshop is ").append(QString::number(total)).append(QString::fromStdString(" euros.")));
     }else{
        ui->showRevenue->setText(QString::fromStdString("There is no revenue."));
     }

}

operationCycle::~operationCycle()
{
    delete ui;
}
