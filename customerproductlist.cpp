#include "customerproductlist.h"
#include "ui_customerproductlist.h"
#include "DBConnection.h"
#include "ProductBase.h"
#include "TV.h"
#include "PC.h"
#include "Smartphone.h"
#include "ProductDAO.h"

CustomerProductList::CustomerProductList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerProductList)
{
    //setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);

    m_db = DBConnection::getInstance().getDB();
    ProductDAO productDao = ProductDAO(m_db);

    //fill Combo Box
    manufacturers = productDao.fetchAllManufacturers();
    for (vector<string>::iterator iter = manufacturers.begin(); iter != manufacturers.end(); iter++) {
         ui->comboBox->addItem(iter->data());
    }

    //Print the Table
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

CustomerProductList::~CustomerProductList()
{
    delete ui;
}


void CustomerProductList::on_showAll_clicked()
{
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

void CustomerProductList::on_showTVs_clicked()
{
    ProductDAO productDao = ProductDAO(m_db);
    products = productDao.fetchAllTVsFromDB();

    ui->table->setColumnCount(9);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ;Photo Url; Description; Price; Availability;Screen Size; 3D").split(";"));
    ui->table->setRowCount(products.size());
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        TV tv = productDao.fetchTVDetailsFromDB(iter->getProduct().getSerial());
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(tv.getSerial())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(tv.getModel())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(tv.getManufacturer())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(tv.getPhotoUrl())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(tv.getDescription())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(tv.getPrice())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::number(iter->getQuantity())));
        ui->table->setItem(row,7,new QTableWidgetItem(QString::number(tv.getScreenSize())));
        if(tv.getCanShow3d()){
            ui->table->setItem(row,8,new QTableWidgetItem(QString::fromStdString("Yes")));
        }else{
            ui->table->setItem(row,8,new QTableWidgetItem(QString::fromStdString("No")));
        }
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

void CustomerProductList::on_showPCs_clicked()
{
    ProductDAO productDao = ProductDAO(m_db);
    products = productDao.fetchAllPCsFromDB();

    ui->table->setColumnCount(12);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ;Photo Url; Description; Price; Availability;Ram;CPU;Disk Type;Disk Space; GPU").split(";"));
    ui->table->setRowCount(products.size());
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        PC pc = productDao.fetchPCDetailsFromDB(iter->getProduct().getSerial());
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(pc.getSerial())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(pc.getModel())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(pc.getManufacturer())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(pc.getPhotoUrl())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(pc.getDescription())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(pc.getPrice())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::number(iter->getQuantity())));
        ui->table->setItem(row,7,new QTableWidgetItem(QString::number(pc.getRam())));
        ui->table->setItem(row,8,new QTableWidgetItem(QString::number(pc.getCpu())));
        ui->table->setItem(row,9,new QTableWidgetItem(QString::fromStdString(pc.getDiskType())));
        ui->table->setItem(row,10,new QTableWidgetItem(QString::number(pc.getDiskSpace())));
        ui->table->setItem(row,11,new QTableWidgetItem(QString::fromStdString(pc.getGpu())));
        row++;

    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

void CustomerProductList::on_showSmPhones_clicked()
{
    ProductDAO productDao = ProductDAO(m_db);
    products = productDao.fetchAllProductsFromDB();

    ui->table->setColumnCount(10);
    ui->table->setHorizontalHeaderLabels(QString("Serial; Model ;Manufacturer ;Photo Url; Description; Price; Availability; Screen Size; Battery Life; Rec 4K").split(";"));
    ui->table->setRowCount(products.size());
    int row=0;
    for (vector<Availability>::iterator iter = products.begin(); iter != products.end(); iter++) {
        Smartphone sp = productDao.fetchSmartphoneDetailsFromDB(iter->getProduct().getSerial());
        ui->table->setItem(row,0,new QTableWidgetItem(QString::number(sp.getSerial())));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(sp.getModel())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(sp.getManufacturer())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(sp.getPhotoUrl())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(sp.getDescription())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::number(sp.getPrice())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::number(iter->getQuantity())));
        ui->table->setItem(row,7,new QTableWidgetItem(QString::number(sp.getScreenSize())));
        ui->table->setItem(row,8,new QTableWidgetItem(QString::number(sp.getBatteryLife())));
        if(sp.getCanRecord4k()){
            ui->table->setItem(row,9,new QTableWidgetItem(QString::fromStdString("Yes")));
        }else{
            ui->table->setItem(row,9,new QTableWidgetItem(QString::fromStdString("No")));
        }
        row++;

    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

void CustomerProductList::on_comboBox_activated(const QString &arg1)
{

            ProductDAO productDao = ProductDAO(m_db);
            products = productDao.fetchProductsByManufacturer(arg1.toLatin1().constData());

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
