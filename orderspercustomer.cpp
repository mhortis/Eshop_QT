#include "orderspercustomer.h"
#include "ui_orderspercustomer.h"

OrdersPerCustomer::OrdersPerCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrdersPerCustomer)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void OrdersPerCustomer::setCustomers(vector<int> customers){
    this->customers = customers;
}

void OrdersPerCustomer::showCustomers(){
    for(vector<int>::iterator iter = customers.begin(); iter != customers.end(); iter++){
        ui->comboBox->addItem(QString::number(*iter));
    }
    ui->comboBox->show();
}

OrdersPerCustomer::~OrdersPerCustomer()
{
    delete ui;
}

void OrdersPerCustomer::on_pushButton_clicked()
{
    OrdersListAndUpdate orderListAndUpdate;
    OrderDAO orderDAO(m_db);
    vector<Order> orders = orderDAO.fetchOrderByCustomer(ui->comboBox->currentText().toInt());
    orderListAndUpdate.setOrders(orders);
    orderListAndUpdate.showOrders();
    orderListAndUpdate.exec();
}
