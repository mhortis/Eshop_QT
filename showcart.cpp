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

    ui->table->setColumnCount(5);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ; Price; Quantity").split(";"));
    ui->table->setRowCount(Cart::getInstance().getCart().size());
    int row=0;
    if(!Cart::getInstance().getCart().empty()){
        for (map<ProductBase,int>::iterator iter = Cart::getInstance().getCart().begin(); iter != Cart::getInstance().getCart().end(); iter++) {
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
    }
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

showCart::~showCart()
{
    delete ui;
}

void showCart::on_pushButton_clicked()
{

}
