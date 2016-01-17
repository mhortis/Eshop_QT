#include "customerorders.h"
#include "ui_customerorders.h"

CustomerOrders::CustomerOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerOrders)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void CustomerOrders::setOrders(vector<Order> orders){
    this->orders = orders;
}

void CustomerOrders::showOrders(){
    ui->table->setColumnCount(3);
    ui->table->setRowCount(this->orders.size());
    ui->table->setHorizontalHeaderLabels(QString("Order number; Order status; Order cost").split(";"));
    int row = 0;

    for(vector<Order>::iterator iter = this->orders.begin(); iter != this->orders.end(); iter++){
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(iter->getOrderNumber())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(iter->getOrderStatus())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::number(iter->getOrderCost())));

        row++;
    }

    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

CustomerOrders::~CustomerOrders()
{
    delete ui;
}

void CustomerOrders::on_table_doubleClicked(const QModelIndex &index)
{
    Order curOrder = orders.at(index.row());
    CustomerOrder customerOrder;
    customerOrder.setOrder(curOrder);
    customerOrder.showOrderItems();
    customerOrder.setModal(true);
    customerOrder.exec();
}

void CustomerOrders::on_cancelOrder_clicked()
{
    QModelIndexList indexes = ui->table->selectionModel()->selectedIndexes();
    QModelIndex index;
    for (int i = 0; i < indexes.count(); ++i)
    {
        index = indexes.at(i);
    }

    Order order = orders.at(index.row());
    if(order.getOrderStatus() != "PROCESSING"){
        QMessageBox::warning(
                this,
                tr("Order can't be cancelled"),
                tr("This order can't be cancelled! Only 'Processing' orders can be cancelled") );
    }
    else{
        OrderDAO orderDAO(m_db);
        orderDAO.updateOrderStatusInDB(order.getOrderNumber(), "CANCELLED");
        QMessageBox::warning(
                this,
                tr("Order cancelled"),
                tr("The order has been cancelled!") );
        ui->table->repaint();
    }
}
