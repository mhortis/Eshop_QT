#include "addpcform.h"
#include "ui_addpcform.h"
#include "mainwindow.h"
#include "PC.h"
#include "ProductDAO.h"
#include <QByteArray>

AddPcForm::AddPcForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPcForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AddPcForm::~AddPcForm()
{
    delete ui;
}

void AddPcForm::on_cancelButton_clicked()
{
    this->hide();
}

void AddPcForm::on_saveButton_clicked()
{
    QByteArray  model,manufacturer,photourl,description,disktype,gpu;
    double price,cpu;
    int ram,diskspace,availability;
    model = ui->modelLineEdit->text().toLatin1();
    manufacturer = ui->manufacturerLineEdit->text().toLatin1();
    photourl = ui->photoUrlLineEdit->text().toLatin1();
    description = ui->descriptionLineEdit->text().toLatin1();
    disktype = ui->diskTypeLineEdit->text().toLatin1();
    gpu = ui->gPULineEdit->text().toLatin1();
    ram = ui->ramLineEdit->text().toInt();
    price = ui->priceLineEdit->text().toDouble();
    cpu = ui->cpuLineEdit->text().toDouble();
    diskspace = ui->diskSpaceLineEdit->text().toInt();
    availability = ui->availabilityLineEdit->text().toInt();
    //Create a new PC
    PC p= PC();
    p.setModel(model.constData());
    p.setManufacturer(manufacturer.constData());
    p.setPhotoUrl(photourl.constData());
    p.setDescription(description.constData());
    p.setDiskType(disktype.constData());
    p.setGpu(gpu.constData());
    p.setDiskSpace(diskspace);
    p.setPrice(price);
    p.setCpu(cpu);
    p.setRam(ram);
    //Save PC to db
    ProductDAO productDao = ProductDAO(m_db);
    productDao.insertProductInDB(p,availability);
    this->hide();
}
