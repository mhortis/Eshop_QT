#include "adminlistcustomers.h"
#include "ui_adminlistcustomers.h"
#include "UserDAO.h"
#include "UserBase.h"
#include "Company.h"
#include "Person.h"

AdminListCustomers::AdminListCustomers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminListCustomers)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();

}

AdminListCustomers::~AdminListCustomers()
{
    delete ui;
}


void AdminListCustomers::on_showPers_clicked()
{
    UserDAO userDao = UserDAO(m_db);
    persons = userDao.fetchPersonsFromDB();


    ui->table->setColumnCount(7);
    ui->table->setHorizontalHeaderLabels(QString("Type of User; Name ;Surname ;Identity; AFM; Phone; Address").split(";"));
    ui->table->setRowCount(persons.size());

    int row=0;
    for (vector<Person>::iterator iter = persons.begin(); iter != persons.end(); iter++) {
        Person person = userDao.fetchPersonDetailsFromDB(iter->getUserID());
        ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString("Person")));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(person.getName())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(person.getSurname())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(person.getIdentity())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(person.getAfm())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::fromStdString(person.getPhoneNumber())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::fromStdString(person.getAddress())));
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}

void AdminListCustomers::on_showComp_clicked()
{
    UserDAO userDao = UserDAO(m_db);
    companies = userDao.fetchCompaniesFromDB();

    ui->table->setColumnCount(9);
    ui->table->setHorizontalHeaderLabels(QString("Type of User; Company\'s Name ;Representative's Name; Surname ;Discount Amount; Phone; FAX; AFM; Address ").split(";"));
    ui->table->setRowCount(companies.size());

    int row=0;
    for (vector<Company>::iterator iter = companies.begin(); iter != companies.end(); iter++) {
        Company company = userDao.fetchCompanyDetailsFromDB(iter->getUserID());
        ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString("Company")));
        ui->table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(company.getCompanyName())));
        ui->table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(company.getResponsibleName())));
        ui->table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(company.getResponsibleSurname())));
        ui->table->setItem(row,4,new QTableWidgetItem(QString::number(company.getDiscount())));
        ui->table->setItem(row,5,new QTableWidgetItem(QString::fromStdString(company.getPhoneNumber())));
        ui->table->setItem(row,6,new QTableWidgetItem(QString::fromStdString(company.getFax())));
        ui->table->setItem(row,7,new QTableWidgetItem(QString::fromStdString(company.getAfm())));
        ui->table->setItem(row,8,new QTableWidgetItem(QString::fromStdString(company.getAddress())));
        row++;
    }
    ui->table->sortItems(0);
    ui->table->resizeRowsToContents();
    ui->table->resizeColumnsToContents();
    ui->table->show();
}
