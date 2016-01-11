#include "stdafx.h"
#include "UserDAO.h"
#include "UserBase.h"


UserDAO::UserDAO(QSqlDatabase database)
{
	db = database;
}

int UserDAO::insertAdminInDB(Administrator admin) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("insert into users (TYPE, USERNAME, PASSWORD)" \
        "values(0, ?, ?);");
    query.addBindValue(QString::fromStdString(admin.getUsername()));
    query.addBindValue(QString::fromStdString(admin.getPassword()));

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new administrator. Error code: %d\n", query.lastError());
        return false;
    }
}

int UserDAO::insertPersonInDB(Person cust) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("insert into users (TYPE, USERNAME, PASSWORD, AFM, PHONE, ADDRESS, " \
		"NAME, SURNAME, IDENTITY)" \
        "values(1, ?, ?, ?, ?, ?, ?, ?, ?);");
    query.addBindValue(QString::fromStdString(cust.getUsername()));
    query.addBindValue(QString::fromStdString(cust.getPassword()));
    query.addBindValue(QString::fromStdString(cust.getAfm()));
    query.addBindValue(QString::fromStdString(cust.getPhoneNumber()));
    query.addBindValue(QString::fromStdString(cust.getAddress()));
    query.addBindValue(QString::fromStdString(cust.getName()));
    query.addBindValue(QString::fromStdString(cust.getSurname()));
    query.addBindValue(QString::fromStdString(cust.getIdentity()));

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new customer. Error code: %d\n", query.lastError());
        return false;
    }
}

int UserDAO::insertCompanyInDB(Company cust) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("insert into users (TYPE, USERNAME, PASSWORD, AFM, PHONE, ADDRESS, " \
		"COMPANY_NAME, RESPONSIBLE_NAME, RESPONSIBLE_SURNAME, DISCOUNT, FAX)" \
        "values(?, ?, ?, ?, ?, ?, ?, ?, ?);");
    query.addBindValue(QString::fromStdString(cust.getUsername()));
    query.addBindValue(QString::fromStdString(cust.getPassword()));
    query.addBindValue(QString::fromStdString(cust.getAfm()));
    query.addBindValue(QString::fromStdString(cust.getPhoneNumber()));
    query.addBindValue(QString::fromStdString(cust.getAddress()));
    query.addBindValue(QString::fromStdString(cust.getCompanyName()));
    query.addBindValue(QString::fromStdString(cust.getResponsibleName()));
    query.addBindValue(QString::fromStdString(cust.getResponsibleSurname()));
    query.addBindValue(cust.getDiscount());
    query.addBindValue(QString::fromStdString(cust.getFax()));

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in insertion of new company. Error code: %d\n", query.lastError());
        return false;
    }
}

int UserDAO::removeUserFromDB(int userID) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        return 0;
    }

    QSqlQuery query;

    query.prepare("delete from products where ID = ?");

    query.addBindValue(userID);

    if(query.exec()){
        return true;
    }
    else{
        fprintf(stderr, "Error in deletion of user. Error code: %d\n", query.lastError());
        return false;
    }
}

UserBase UserDAO::fetchUserByIDFromDB(int userID) {
    if (!db.open()) {
        fprintf(stderr, "Invalid or unset database.");
        UserBase user;
        return user;
    }

    QSqlQuery query;

    query.prepare("SELECT * from users where ID=?");
    query.addBindValue(userID);

    if(query.exec()){
        while(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 0){
                Administrator admin = Administrator(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                                                    query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
                admin.setUserID(query.value(query.record().indexOf("ID")).toInt());
                return admin;
            }
            else if(query.value(query.record().indexOf("TYPE")) == 1){
                Person person = Person(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                        query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
                person.setUserID(query.value(query.record().indexOf("ID")).toInt());
                person.setAfm(query.value(query.record().indexOf("AFM")).toString().toLocal8Bit().constData());
                person.setPhoneNumber(query.value(query.record().indexOf("PHONE")).toString().toLocal8Bit().constData());
                person.setAddress(query.value(query.record().indexOf("ADDRESS")).toString().toLocal8Bit().constData());
                person.setName(query.value(query.record().indexOf("NAME")).toString().toLocal8Bit().constData());
                person.setSurname(query.value(query.record().indexOf("SURNAME")).toString().toLocal8Bit().constData());
                person.setIdentity(query.value(query.record().indexOf("IDENTITY")).toString().toLocal8Bit().constData());
                return person;
            }
            else{
                Company company = Company(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                                          query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
                company.setUserID(query.value(query.record().indexOf("ID")).toInt());
                company.setAfm(query.value(query.record().indexOf("AFM")).toString().toLocal8Bit().constData());
                company.setPhoneNumber(query.value(query.record().indexOf("PHONE")).toString().toLocal8Bit().constData());
                company.setAddress(query.value(query.record().indexOf("ADDRESS")).toString().toLocal8Bit().constData());
                company.setCompanyName(query.value(query.record().indexOf("COMPANY_NAME")).toString().toLocal8Bit().constData());
                company.setResponsibleName(query.value(query.record().indexOf("RESPONSIBLE_NAME")).toString().toLocal8Bit().constData());
                company.setResponsibleSurname(query.value(query.record().indexOf("RESPONSIBLE_SURNAME")).toString().toLocal8Bit().constData());
                company.setDiscount(query.value(query.record().indexOf("DISCOUNT")).toDouble());
                company.setFax(query.value(query.record().indexOf("FAX")).toString().toLocal8Bit().constData());
                return company;
            }
        }
    }
    else{
        fprintf(stderr, "Error in fetching users. Error code: %d\n", query.lastError());
        UserBase user;
        return user;
    }
}
