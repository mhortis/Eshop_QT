#include "customerpanel.h"
#include "ui_customerpanel.h"
#include "logoutdialog.h"
#include <QStringList>
#include "customerproductlist.h"
#include "cart.h"
#include "showcart.h"

CustomerPanel::CustomerPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerPanel)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void CustomerPanel::setCustomer(Customer cust){
    this->customer = cust;
}

void CustomerPanel::setCart(map<ProductBase, int> cart){
    this->customer.setCart(cart);
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
    LogoutDialog logout(this->getPanelType());
    logout.show();
}

void CustomerPanel::on_actionList_Products_triggered()
{
    CustomerProductList productList;
    productList.exec();

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
        customerOrders.exec();
    }
}

void CustomerPanel::on_actionNew_Order_triggered()
{
    if(Cart::getInstance().getCart().empty()){
        QMessageBox::warning(
                this,
                tr("No products in cart"),
                tr("There are no products in your cart!") );
    }
    else{
        Order order;
        order.setOrderBuyer(customer);
        order.setOrderStatus("Processing");
//        order.setOrderItems(Cart::getInstance().getCart());
//        order.setOrderCost(Cart::getInstance().getCart());
        NewOrder newOrder;
        newOrder.setOrder(order);
        newOrder.showOrder();
        newOrder.exec();
    }
}

void CustomerPanel::on_actionShow_Cart_triggered()
{
    showCart theCart;
    theCart.exec();
}
