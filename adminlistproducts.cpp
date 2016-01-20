#include "adminlistproducts.h"
#include "ui_adminlistproducts.h"
#include <QTableWidget>
#include <QTableWidgetItem>

using namespace std;

AdminListProducts::AdminListProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminListProducts)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
    ProductDAO productDao = ProductDAO(m_db);
    products = productDao.fetchAllProductsFromDB();

    ui->table->setColumnCount(7);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ;Photo Url; Description; Price; Availability").split(";"));
    ui->table->setRowCount(products.size());
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        ProductBase product = iter->getProduct();
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(product.getSerial())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(product.getModel())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(product.getManufacturer())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(product.getPhotoUrl())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(product.getDescription())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(product.getPrice())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::number(iter->getQuantity())));

        row++;

    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();

}

AdminListProducts::~AdminListProducts()
{
    delete ui;
}

void AdminListProducts::on_table_doubleClicked(const QModelIndex &index)
{
    ProductBase curProduct = products.at(index.row()).getProduct();
    int availability = products.at(index.row()).getQuantity();
    if(curProduct.getType() == 0){
        UpdatePC updatePC;
        updatePC.setProduct(curProduct, availability);
        updatePC.showProduct();
        updatePC.exec();
    }
    else if(curProduct.getType() == 1){
        UpdateSmartphone updateSmartphone;
        updateSmartphone.setProduct(curProduct, availability);
        updateSmartphone.showProduct();
        updateSmartphone.exec();
    }
    else if(curProduct.getType() == 2){
        UpdateTV updateTV;
        updateTV.setProduct(curProduct, availability);
        updateTV.showProduct();
        updateTV.exec();
    }
}
