#include "updatepc.h"
#include "ui_updatepc.h"

UpdatePC::UpdatePC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePC)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

void UpdatePC::setProduct(ProductBase prod, int availability){
    this->product = prod;
    this->availability = availability;
}

void UpdatePC::showProduct(){
    ProductDAO productDao = ProductDAO(m_db);
    pc = productDao.fetchPCDetailsFromDB(product.getSerial());

    ui->table->setColumnCount(11);
    ui->table->setRowCount(1);
    ui->table->setHorizontalHeaderLabels(QString("Model ;Manufacturer ;Photo Url; Description; Price; CPU; Disk type; Disk space; RAM; GPU; Availability").split(";"));
    int row=0;
    ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(pc.getModel())));
    ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(pc.getManufacturer())));
    ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(pc.getPhotoUrl())));
    ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(pc.getDescription())));
    ui->table->setItem(row,4,new QTableWidgetItem(QString::number(pc.getPrice())));
    ui->table->setItem(row,5,new QTableWidgetItem(QString::number(pc.getCpu())));
    ui->table->setItem(row,6,new QTableWidgetItem(QString::fromStdString(pc.getDiskType())));
    ui->table->setItem(row,7,new QTableWidgetItem(QString::number(pc.getDiskSpace())));
    ui->table->setItem(row,8,new QTableWidgetItem(QString::number(pc.getRam())));
    ui->table->setItem(row,9,new QTableWidgetItem(QString::fromStdString(pc.getGpu())));
    ui->table->setItem(row,10,new QTableWidgetItem(QString::number(availability)));

    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

UpdatePC::~UpdatePC()
{
    delete ui;
}

void UpdatePC::on_updateButton_clicked()
{
    PC newPc;
    newPc.setSerial(pc.getSerial());
    newPc.setModel(ui->table->item(0,0)->text().toLocal8Bit().constData());
    newPc.setManufacturer(ui->table->item(0,1)->text().toLocal8Bit().constData());
    newPc.setPhotoUrl(ui->table->item(0,2)->text().toLocal8Bit().constData());
    newPc.setDescription(ui->table->item(0,3)->text().toLocal8Bit().constBegin());
    newPc.setPrice(ui->table->item(0,4)->text().toDouble());
    newPc.setCpu(ui->table->item(0,5)->text().toInt());
    newPc.setDiskType(ui->table->item(0,6)->text().toLocal8Bit().constData());
    newPc.setDiskSpace(ui->table->item(0,7)->text().toInt());
    newPc.setRam(ui->table->item(0,8)->text().toInt());
    newPc.setGpu(ui->table->item(0,9)->text().toLocal8Bit().constData());
    int avail = ui->table->item(0,10)->text().toInt();

    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.updateProductInDB(newPc);
    productDAO.updateProductItemsInDB(pc.getSerial(), avail);
    this->close();
}

void UpdatePC::on_cancelButton_clicked()
{
    this->close();
}

void UpdatePC::on_removeButton_clicked()
{
    ProductDAO productDAO = ProductDAO(m_db);
    productDAO.removeProductFromDB(pc.getSerial());
    this->close();
}
