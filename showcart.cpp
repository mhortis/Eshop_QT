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
        ui->table->item(row,0)->setFlags(ui->table->item(row,0)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,1)->setFlags(ui->table->item(row,1)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,2)->setFlags(ui->table->item(row,2)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,3)->setFlags(ui->table->item(row,3)->flags() ^ Qt::ItemIsEditable);
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

void showCart::on_removeItem_clicked()
{
    QModelIndexList indexes = ui->table->selectionModel()->selectedIndexes();
    QModelIndexList RowsSelected = ui->table->selectionModel()->selectedRows();
    QModelIndex index;
    m_db = DBConnection::getInstance().getDB();
    ProductBase product;
    cart = Cart::getInstance();
    customer.setCart(cart.getCart());
    int serial;
    //Remove the specific Item
    for (map<ProductBase,int>::iterator iter = cart.getCart().begin(); iter != cart.getCart().end(); iter++) {
        product = iter->first;
        for (int i = 0; i < RowsSelected.count(); ++i)
        {
            index = RowsSelected.at(i);
            serial =  ui->table->model()->data(index).toInt();
            if(product.getSerial()== serial){
                cart.getCart().erase(iter);
                //customer.removeProductFromCart(product);
                //ui->table->removeRow(index.row());
            }
        }
    }
    // Print again the Cart
    //cart.setCart(customer.getCart());
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
        ui->table->item(row,0)->setFlags(ui->table->item(row,0)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,1)->setFlags(ui->table->item(row,1)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,2)->setFlags(ui->table->item(row,2)->flags() ^ Qt::ItemIsEditable);
        ui->table->item(row,3)->setFlags(ui->table->item(row,3)->flags() ^ Qt::ItemIsEditable);
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();

}
