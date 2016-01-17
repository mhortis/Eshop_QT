#include "updatesmartphone.h"
#include "ui_updatesmartphone.h"

UpdateSmartphone::UpdateSmartphone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateSmartphone)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void UpdateSmartphone::setProduct(ProductBase prod, int availability){
    this->product = prod;
    this->availability = availability;
}

void UpdateSmartphone::showProduct(){
    ProductDAO productDao = ProductDAO(m_db);
    smartphone = productDao.fetchSmartphoneDetailsFromDB(product.getSerial());

    ui->table->setColumnCount(9);
    ui->table->setRowCount(1);
    ui->table->setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price; Screen size; Battery life; Can record 4K; Availability").split(";"));
    int row=0;
    ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(smartphone.getModel())));
    ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(smartphone.getManufacturer())));
    ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(smartphone.getPhotoUrl())));
    ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(smartphone.getDescription())));
    ui->table->setItem(row,4,new QTableWidgetItem(QString::number(smartphone.getPrice())));
    ui->table->setItem(row,5,new QTableWidgetItem(QString::number(smartphone.getScreenSize())));
    ui->table->setItem(row,6,new QTableWidgetItem(QString::number(smartphone.getBatteryLife())));
    ui->table->setItem(row,7,new QTableWidgetItem(QString::number(smartphone.getCanRecord4k())));
    ui->table->setItem(row,8,new QTableWidgetItem(QString::number(availability)));

    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

UpdateSmartphone::~UpdateSmartphone()
{
    delete ui;
}

void UpdateSmartphone::on_updateButton_clicked()
{
    Smartphone newSmartphone;
    newSmartphone.setSerial(smartphone.getSerial());
    newSmartphone.setModel(ui->table->item(0,0)->text().toLocal8Bit().constData());
    newSmartphone.setManufacturer(ui->table->item(0,1)->text().toLocal8Bit().constData());
    newSmartphone.setPhotoUrl(ui->table->item(0,2)->text().toLocal8Bit().constData());
    newSmartphone.setDescription(ui->table->item(0,3)->text().toLocal8Bit().constBegin());
    newSmartphone.setPrice(ui->table->item(0,4)->text().toDouble());
    newSmartphone.setScreenSize(ui->table->item(0,5)->text().toDouble());
    newSmartphone.setBatteryLife(ui->table->item(0,6)->text().toInt());
    newSmartphone.setCanRecord4k(ui->table->item(0,7)->text().toInt());

    int avail = ui->table->item(0,8)->text().toInt();

    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.updateProductInDB(newSmartphone);
    productDAO.updateProductItemsInDB(smartphone.getSerial(), avail);
    this->close();
}

void UpdateSmartphone::on_cancelButton_clicked()
{
    this->close();
}

void UpdateSmartphone::on_removeButton_clicked()
{
    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.removeProductFromDB(smartphone.getSerial());
    this->close();
}
