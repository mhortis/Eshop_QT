#include "customerorcompany.h"
#include "ui_customerorcompany.h"
#include "addcustomerform.h"
#include "addcompanyform.h"

CustomerOrCompany::CustomerOrCompany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerOrCompany)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

CustomerOrCompany::~CustomerOrCompany()
{
    delete ui;
}

void CustomerOrCompany::on_addCompany_clicked()
{
    this->hide();
    AddCompanyForm addCompany;
    addCompany.exec();
}

void CustomerOrCompany::on_addCustomer_clicked()
{
    this->hide();
    AddCustomerForm addCustomer;
    addCustomer.exec();
}
