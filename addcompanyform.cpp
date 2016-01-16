#include "addcompanyform.h"
#include "ui_addcompanyform.h"
#include "Company.h"
#include "mainwindow.h"

AddCompanyForm::AddCompanyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCompanyForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AddCompanyForm::~AddCompanyForm()
{
    delete ui;
}

void AddCompanyForm::on_cancelButton_clicked()
{
    this->hide();
}

void AddCompanyForm::on_saveButton_clicked()
{
    QByteArray  username,password,rname,rsurname,cname,fax,afm,phone,address;
    double discount;
    cname =  ui->cnameLineEdit->text().toLatin1();
    rname = ui->rNameLineEdit->text().toLatin1();
    rsurname = ui->rSurnameLineEdit->text().toLatin1();
    fax = ui->fAXLineEdit->text().toLatin1();
    discount = ui->discountPercentageLineEdit->text().toDouble();
    afm = ui->afmLineEdit->text().toLatin1();
    phone = ui->phoneLineEdit->text().toLatin1();
    address = ui->addressLineEdit->text().toLatin1();
    username = ui->usernameLineEdit->text().toLatin1();
    password = ui->passwordLineEdit->text().toLatin1();
    //Create a new Company
    Company c= Company(username.constData(),password.constData());
    c.setCompanyName(cname.constData());
    c.setResponsibleName(rname.constData());
    c.setResponsibleSurname(rsurname.constData());
    c.setDiscount(discount);
    c.setFax(fax.constData());
    c.setAfm(afm.constData());
    c.setPhoneNumber(phone.constData());
    c.setAddress(address.constData());
    //Save Company to db
    UserDAO userDao = UserDAO(m_db);
    userDao.insertCompanyInDB(c);
    this->hide();
}

