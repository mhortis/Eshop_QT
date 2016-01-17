#include "customerpanel.h"
#include "ui_customerpanel.h"
#include "logoutdialog.h"
#include <QStringList>

CustomerPanel::CustomerPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerPanel)
{
    setAttribute( Qt::WA_DeleteOnClose );
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void CustomerPanel::setCustomer(Customer cust){
    this->customer = cust;
}

CustomerPanel::~CustomerPanel()
{
    delete ui;
}

int CustomerPanel::getPanelType(){
    return panelType;
}

void CustomerPanel::on_actionLogout_triggered()
{
    this->close();
    LogoutDialog *logout = new LogoutDialog(this->getPanelType());
    logout->show();
}

void CustomerPanel::on_actionList_Products_triggered()
{


}

void CustomerPanel::on_actionView_Orders_triggered()
{
    OrderDAO orderDAO(m_db);
    vector<Order> orders = orderDAO.fetchOrderByCustomer(customer.getUserID());
    if(orders.size() == 0){
        QMessageBox::warning(
                this,
                tr("No past orders"),
                tr("There are no past orders for you!") );
    }
    else{
        CustomerOrders customerOrders;
        customerOrders.setOrders(orders);
        customerOrders.showOrders();
        customerOrders.setModal(true);
        customerOrders.exec();
    }
}

void CustomerPanel::on_actionNew_Order_triggered()
{
    if(customer.getCart().empty()){
        QMessageBox::warning(
                this,
                tr("No products in cart"),
                tr("There are no products in your cart!") );
    }
    else{
        Order order;
        order.setOrderBuyer(customer);
        order.setOrderStatus("Processing");
        order.setOrderItems(customer.getCart());
        order.setOrderCost(customer.getCart());
        NewOrder newOrder;
        newOrder.setOrder(order);
        newOrder.showOrder();
        newOrder.setModal(true);
        newOrder.exec();
    }
}
