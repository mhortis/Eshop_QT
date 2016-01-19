#include "showcart.h"
#include "ui_showcart.h"
#include "DBConnection.h"
#include "ProductDAO.h"
#include "ProductBase.h"
#include "cart.h"

showCart::showCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showCart)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
    ProductDAO productDao = ProductDAO(m_db);
    cart = Cart::getInstance();
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
        ui->table->item(row,4)->setFlags(ui->table->item(row,4)->flags() ^ Qt::ItemIsEditable);
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

showCart::~showCart()
{
    delete ui;
}
