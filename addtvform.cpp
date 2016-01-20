#include "addtvform.h"
#include "ui_addtvform.h"
#include "ProductDAO.h"
#include "mainwindow.h"
#include "TV.h"
#include <QByteArray>

AddTvForm::AddTvForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTvForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AddTvForm::~AddTvForm()
{
    delete ui;
}

void AddTvForm::on_cancelButton_clicked()
{
    this->hide();
}

void AddTvForm::on_saveButton_clicked()
{
    QByteArray  model,manufacturer,photourl,description;
    double screensize,price;
    int availability;
    bool can3D;
    model = ui->modelLineEdit->text().toLatin1();
    manufacturer = ui->manufacturerLineEdit->text().toLatin1();
    photourl = ui->photoUrlLineEdit->text().toLatin1();
    description = ui->descriptionLineEdit->text().toLatin1();
    screensize = ui->screenSizeLineEdit->text().toDouble();
    price = ui->priceLineEdit->text().toDouble();
    can3D = ui->show3DBox->isChecked();
    availability = ui->availabilityLineEdit->text().toInt();
    //Create a new TV and set properties
    TV t= TV();
    t.setModel(model.constData());
    t.setManufacturer(manufacturer.constData());
    t.setPhotoUrl(photourl.constData());
    t.setDescription(description.constData());
    t.setScreenSize(screensize);
    t.setPrice(price);
    t.setCanShow3d(can3D);
    //Save TV to db
    ProductDAO productDao = ProductDAO(m_db);
    productDao.insertProductInDB(t,availability);
    this->hide();
}
