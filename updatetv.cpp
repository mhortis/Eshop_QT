#include "updatetv.h"
#include "ui_updatetv.h"

UpdateTV::UpdateTV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateTV)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void UpdateTV::setProduct(ProductBase prod, int availability){
    this->product = prod;
    this->availability = availability;
}

void UpdateTV::showProduct(){
    ProductDAO productDao = ProductDAO(m_db);
    tv = productDao.fetchTVDetailsFromDB(product.getSerial());

    ui->table->setColumnCount(8);
    ui->table->setRowCount(1);
    ui->table->setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price; Screen Size; Can show 3D; Availability").split(";"));
    int row=0;
    ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(tv.getModel())));
    ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(tv.getManufacturer())));
    ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(tv.getPhotoUrl())));
    ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(tv.getDescription())));
    ui->table->setItem(row,4,new QTableWidgetItem(QString::number(tv.getPrice())));
    ui->table->setItem(row,5,new QTableWidgetItem(QString::number(tv.getScreenSize())));
    ui->table->setItem(row,6,new QTableWidgetItem(QString::number(tv.getCanShow3d())));
    ui->table->setItem(row,7,new QTableWidgetItem(QString::number(availability)));

    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

UpdateTV::~UpdateTV()
{
    delete ui;
}

void UpdateTV::on_updateButton_clicked()
{
    TV newTv;
    newTv.setSerial(tv.getSerial());
    newTv.setModel(ui->table->item(0,0)->text().toLocal8Bit().constData());
    newTv.setManufacturer(ui->table->item(0,1)->text().toLocal8Bit().constData());
    newTv.setPhotoUrl(ui->table->item(0,2)->text().toLocal8Bit().constData());
    newTv.setDescription(ui->table->item(0,3)->text().toLocal8Bit().constBegin());
    newTv.setPrice(ui->table->item(0,4)->text().toDouble());
    newTv.setScreenSize(ui->table->item(0,5)->text().toDouble());
    newTv.setCanShow3d(ui->table->item(0,6)->text().toInt());

    int avail = ui->table->item(0,7)->text().toInt();

    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.updateProductInDB(newTv);
    productDAO.updateProductItemsInDB(tv.getSerial(), avail);
    this->close();
}

void UpdateTV::on_cancelButton_clicked()
{
    this->close();
}

void UpdateTV::on_removeButton_clicked()
{
    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.removeProductFromDB(tv.getSerial());
    this->close();
}
