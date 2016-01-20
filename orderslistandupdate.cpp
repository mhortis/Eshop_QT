#include "orderslistandupdate.h"
#include "ui_orderslistandupdate.h"

OrdersListAndUpdate::OrdersListAndUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdersListAndUpdate)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void OrdersListAndUpdate::setOrders(vector<Order> orders){
    this->orders = orders;
}

void OrdersListAndUpdate::showOrders(){
    ui->table->setColumnCount(4);
    ui->table->setRowCount(this->orders.size());
    ui->table->setHorizontalHeaderLabels(QString("Order number; Customer ID; Order status; Order cost").split(";"));
    int row = 0;

    for(vector<Order>::iterator iter = this->orders.begin(); iter != this->orders.end(); iter++){
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(iter->getOrderNumber())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::number(iter->getOrderBuyer().getUserID())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(iter->getOrderStatus())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::number(iter->getOrderCost())));

        ui->table->item(row,0)->setFlags(ui->table->item(row,0)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,3)->setFlags(ui->table->item(row,3)->flags() ^ Qt::ItemIsEditable);
        row++;
    }
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

OrdersListAndUpdate::~OrdersListAndUpdate()
{
    delete ui;
}

void OrdersListAndUpdate::on_saveButton_clicked()
{
    QModelIndexList indexes = ui->table->selectionModel()->selectedIndexes();
    QModelIndex index;
    for (int i = 0; i < indexes.count(); ++i)
    {
        index = indexes.at(i);
    }

    Order order = orders.at(index.row());
    int customerID = ui->table->item(index.row(), 1)->text().toInt();
    string status = ui->table->item(index.row(), 2)->text().toStdString();
    OrderDAO orderDAO(m_db);
    orderDAO.updateOrderBuyerInDB(order.getOrderNumber(), customerID);
    orderDAO.updateOrderStatusInDB(order.getOrderNumber(), status);
    QMessageBox::warning(
            this,
            tr("Order updated"),
            tr("The order customer ID and status have been updated!") );
    this->close();

}

void OrdersListAndUpdate::on_cancelButton_clicked()
{
    this->close();
}
