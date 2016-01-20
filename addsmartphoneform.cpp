#include "addsmartphoneform.h"
#include "ui_addsmartphoneform.h"
#include <QByteArray>
#include "mainwindow.h"
#include "Smartphone.h"
#include "ProductDAO.h"

AddSmartphoneForm::AddSmartphoneForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSmartphoneForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AddSmartphoneForm::~AddSmartphoneForm()
{
    delete ui;
}

void AddSmartphoneForm::on_cancelButton_clicked()
{
    this->hide();
}

void AddSmartphoneForm::on_saveButton_clicked()
{
    QByteArray  model,manufacturer,photourl,description;
    double price,screensize;
    int batteryLife,availability;
    bool can4K;
    model = ui->modelLineEdit->text().toLatin1();
    manufacturer = ui->manufacturerLineEdit->text().toLatin1();
    photourl = ui->photoUrlLineEdit->text().toLatin1();
    description = ui->descriptionLineEdit->text().toLatin1();
    screensize = ui->screenSizeLineEdit->text().toDouble();
    price = ui->priceLineEdit->text().toDouble();
    screensize = ui->screenSizeLineEdit->text().toDouble();
    batteryLife = ui->batteryLifeLineEdit->text().toInt();
    can4K = ui->fourKBox->isChecked();
    availability = ui->availabilityLineEdit->text().toInt();
    //Create a new Smartphone and set properties
    Smartphone s= Smartphone();
    s.setModel(model.constData());
    s.setManufacturer(manufacturer.constData());
    s.setPhotoUrl(photourl.constData());
    s.setDescription(description.constData());
    s.setScreenSize(screensize);
    s.setPrice(price);
    s.setBatteryLife(batteryLife);
    s.setCanRecord4k(can4K);
    //Save Smartphone to db
    ProductDAO productDao = ProductDAO(m_db);
    productDao.insertProductInDB(s,availability);
    this->hide();
}
