#include "neworder.h"
#include "ui_neworder.h"
#include "OrderDAO.h"
#include "Order.h"
#include "Customer.h"
#include "UserDAO.h"
#include "ProductDAO.h"
#include "ProductBase.h"
#include "mainwindow.h"
NewOrder::NewOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOrder)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
    cart = Cart::getInstance();

    ProductDAO productDao = ProductDAO(m_db);
    cartMap = Cart::getInstance().getCart();
    ui->table->setColumnCount(5);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ; Price; Quantity").split(";"));
    ui->table->setRowCount(cart.getCart().size());
    int row=0;
    for (map<ProductBase,int>::iterator iter = cart.getCart().begin(); iter != cart.getCart().end(); iter++) {
        //Availability avail = productDao.fetchProductBySerialFromDB(iter->first);
        ProductBase product = iter->first;
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(product.getSerial())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(product.getModel())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(product.getManufacturer())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::number(product.getPrice())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::number(iter->second)));
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();

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


void NewOrder::on_cancelOrder_clicked()
{
    this->close();
}

void NewOrder::on_placeOrder_clicked()
{/*m_db = DBConnection::getInstance().getDB();
    OrderDAO orderDAO = OrderDAO(m_db);
    UserDAO customerDAO = UserDAO(m_db);
    cartMap = Cart::getInstance().getCart();
    vector<Order> orders = orderDAO.fetchOrderByCustomer( "Kapws na paroume to UserID!");
    customer = customerDAO.fetchUserByIDFromDB(userID);


    //Create a new Order
    order = new Order(cartMap,customer);
    order.setOrderNumber(orders.size()-1);
    order.setOrderBuyer( );
    order.setOrderItems(cartMap);
    order.setOrderCost(cartMap);
    order.setOrderStatus("PROCESSING");
    //Save Order to db
    orderDAO.insertOrderInDB(cartMap,order);
    this->hide();
*/
}
