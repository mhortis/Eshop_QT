#include "adminlistproducts.h"
#include "ui_adminlistproducts.h"
#include "ProductDAO.h"
#include "ProductBase.h"
#include <QTableWidget>
#include <QTableWidgetItem>


using namespace std;

AdminListProducts::AdminListProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminListProducts)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
    QTableWidget table;
    QAbstractItemModel *model = table.model();
    ProductDAO productDao = ProductDAO(m_db);


    table.setColumnCount(5);
    table.setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price;").split(";"));
    vector<Availability> products = productDao.fetchAllProductsFromDB();
    table.setRowCount(products.size());
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        ProductBase product = iter->getProduct();
        table.setItem(row,0,new QTableWidgetItem(QString::fromStdString(product.getModel())));
        table.setItem(row,1,new QTableWidgetItem(QString::fromStdString(product.getManufacturer())));
        table.setItem(row,2,new QTableWidgetItem(QString::fromStdString(product.getPhotoUrl())));
        table.setItem(row,3,new QTableWidgetItem(QString::fromStdString(product.getDescription())));
        table.setItem(row,4,new QTableWidgetItem(QString::number(product.getPrice())));
        QVariant data = model->headerData(row, Qt::Vertical);

        row++;

    }
    table.resizeRowsToContents();
    table.resizeColumnsToContents();
    table.show();
    //modal->
    //ui->tableView->setModel(modal);
    //ui->tableWidget->show();
}

AdminListProducts::~AdminListProducts()
{
    delete ui;
}

void AdminListProducts::listAllProducts(){
    ProductDAO productDao = ProductDAO(m_db);
    QTableWidget table;
    table.setColumnCount(5);
    table.setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price;").split(";"));
    vector<Availability> products = productDao.fetchAllProductsFromDB();
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        ProductBase product = iter->getProduct();
        table.setItem(row,0,new QTableWidgetItem(QString::fromStdString(product.getModel())));
        table.setItem(row,1,new QTableWidgetItem(QString::fromStdString(product.getManufacturer())));
        table.setItem(row,2,new QTableWidgetItem(QString::fromStdString(product.getPhotoUrl())));
        table.setItem(row,3,new QTableWidgetItem(QString::fromStdString(product.getDescription())));
        table.setItem(row,4,new QTableWidgetItem(QString::number(product.getPrice())));
        row++;

    }
    table.resizeRowsToContents();
    table.resizeColumnsToContents();
}

