#include "addcustomerform.h"
#include "ui_addcustomerform.h"
#include "UserDAO.h"
#include "mainwindow.h"
#include <QByteArray>

AddCustomerForm::AddCustomerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();

}

AddCustomerForm::~AddCustomerForm()
{
    delete ui;
}

void AddCustomerForm::on_cancelButton_clicked()
{
    this->hide();
}

void AddCustomerForm::on_saveButton_clicked()
{
    QByteArray  username,password,name,surname,identity,afm,phone,address;
    name =  ui->nameLineEdit->text().toLatin1();
    surname = ui->surnameLineEdit->text().toLatin1();
    identity = ui->idnumberLineEdit->text().toLatin1();
    afm = ui->afmLineEdit->text().toLatin1();
    phone = ui->phoneLineEdit->text().toLatin1();
    address = ui->addressLineEdit->text().toLatin1();
    username = ui->usernameLineEdit->text().toLatin1();
    password = ui->passowordLineEdit->text().toLatin1();
    //Create a new Customer
    Person p = Person(username.constData(),password.constData());
    p.setName(name.constData());
    p.setSurname(surname.constData());
    p.setIdentity(identity.constData());
    p.setAfm(afm.constData());
    p.setPhoneNumber(phone.constData());
    p.setAddress(address.constData());
    //Save Customer to db
    UserDAO userDao = UserDAO(m_db);
    userDao.insertPersonInDB(p);
}
