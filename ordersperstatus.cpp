#include "ordersperstatus.h"
#include "ui_ordersperstatus.h"

OrdersPerStatus::OrdersPerStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdersPerStatus)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();

    ui->comboBox->addItem("PROCESSING");
    ui->comboBox->addItem("PROCESSED");
    ui->comboBox->addItem("ON DELIVERY");
    ui->comboBox->addItem("DELIVERED");

    ui->comboBox->show();

}

OrdersPerStatus::~OrdersPerStatus()
{
    delete ui;
}

void OrdersPerStatus::on_pushButton_clicked()
{
    OrdersListAndUpdate orderListAndUpdate;
    OrderDAO orderDAO(m_db);
    vector<Order> orders = orderDAO.fetchOrdersByStatus(ui->comboBox->currentText().toStdString());
    if(orders.empty()){
        QMessageBox::warning(
                this,
                tr("No orders"),
                tr("There are no orders with the selected status!") );
    }
    else{
        orderListAndUpdate.setOrders(orders);
        orderListAndUpdate.showOrders();
        orderListAndUpdate.exec();
    }
}
