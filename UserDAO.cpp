#include "stdafx.h"
#include "UserDAO.h"
#include "UserBase.h"


UserDAO::UserDAO(QSqlDatabase database)
{
	db = database;
}

int UserDAO::insertAdminInDB(Administrator admin) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return 0;
    }

    QSqlQuery query(db);

    query.prepare("insert into users (TYPE, USERNAME, PASSWORD)" \
        "values(0, ?, ?);");
    query.addBindValue(QString::fromStdString(admin.getUsername()));
    query.addBindValue(QString::fromStdString(admin.getPassword()));

    if(query.exec()){
        return true;
    }
    else{
        qDebug() << "Error in insertion of new administrator. Error code: " << query.lastError() << endl;
        return false;
    }
}

int UserDAO::insertPersonInDB(Person cust) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return 0;
    }

    QSqlQuery query(db);

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
        qDebug() << "Error in insertion of new customer. Error code: " << query.lastError() << endl;
        return false;
    }
}

int UserDAO::insertCompanyInDB(Company cust) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return 0;
    }

    QSqlQuery query(db);

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
        qDebug() << "Error in insertion of new company. Error code: " << query.lastError() << endl;
        return false;
    }
}

int UserDAO::removeUserFromDB(int userID) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return 0;
    }

    QSqlQuery query(db);

    query.prepare("delete from products where ID = ?");

    query.addBindValue(userID);

    if(query.exec()){
        return true;
    }
    else{
        qDebug() << "Error in deletion of user. Error code: " << query.lastError() << endl;
        return false;
    }
}

int UserDAO::userExistsInDB(string username, string password){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        return -1;
    }

    QSqlQuery query(db);

    query.prepare("SELECT count(*) from users where USERNAME=? AND PASSWORD=?");
    query.addBindValue(username.c_str());
    query.addBindValue(password.c_str());

    if(query.exec()){
        if(query.next()){
            int count = query.value(0).toInt();
            return count;
        }
        else{
            qDebug() << "Error in fetching count of users. Error code: " << query.lastError() << endl;
            return -1;
        }
    }
    else{
        qDebug() << "Error in fetching count of users. Error code: " << query.lastError() << endl;
        return -1;
    }
}

UserBase UserDAO::fetchUserByIDFromDB(int userID) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        UserBase user;
        return user;
    }

    QSqlQuery query(db);

    query.prepare("SELECT * from users where ID=?");
    query.addBindValue(userID);

    if(query.exec()){
        if(query.next()){
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
        else{
            qDebug() << "Error in fetching user by ID. Error code: " << query.lastError() << endl;
            UserBase user;
            return user;
        }
    }
    else{
        qDebug() << "Error in fetching users. Error code: " << query.lastError() << endl;
        UserBase user;
        return user;
    }
}

UserBase UserDAO::fetchUserByUsernamePwdFromDB(string username, string password) {
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        UserBase user;
        return user;
    }

    QSqlQuery query(db);

    query.prepare("SELECT * from users where USERNAME=? AND PASSWORD=?");
    query.addBindValue(username.c_str());
    query.addBindValue(password.c_str());

    if(query.exec()){
        if(query.next()){
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
        else{
            qDebug() << "Error in fetching user by username and password. Error code: " << query.lastError() << endl;
            UserBase user;
            return user;
        }
    }
    else{
        qDebug() << "Error in fetching users. Error code: " << query.lastError() << endl;
        UserBase user;
        return user;
    }
}

Person UserDAO::fetchPersonDetailsFromDB(int userID){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        Person user;
        return user;
    }

    QSqlQuery query(db);

    query.prepare("SELECT * from users where ID=?");
    query.addBindValue(userID);

    if(query.exec()){
        if(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 1){
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
                qDebug() << "Error in fetching Person by ID. This is not a Person. Error code: " << query.lastError() << endl;
                Person user;
                return user;
            }
        }
        else{
            qDebug() << "Error in fetching user by ID. Error code: " << query.lastError() << endl;
            Person user;
            return user;
        }
    }
    else{
        qDebug() << "Error in fetching users. Error code: " << query.lastError() << endl;
        Person user;
        return user;
    }
}

Company UserDAO::fetchCompanyDetailsFromDB(int userID){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        Company user;
        return user;
    }

    QSqlQuery query(db);

    query.prepare("SELECT * from users where ID=?");
    query.addBindValue(userID);

    if(query.exec()){
        if(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 2){
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
            else{
                qDebug() << "Error in fetching Company by ID. This is not a Company. Error code: " << query.lastError() << endl;
                Company user;
                return user;
            }
        }
        else{
            qDebug() << "Error in fetching user by ID. Error code: " << query.lastError() << endl;
            Company user;
            return user;
        }
    }
    else{
        qDebug() << "Error in fetching users. Error code: " << query.lastError() << endl;
        Company user;
        return user;
    }
}

vector<UserBase> UserDAO::fetchUsersFromDB(){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        vector<UserBase> users;
        return users;
    }

    QSqlQuery query(db);
    vector<UserBase> users;
    query.prepare("SELECT * from users");

    if(query.exec()){
        while(query.next()){
            if(query.value(query.record().indexOf("TYPE")) == 0){
                Administrator admin = Administrator(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                                                    query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
                admin.setUserID(query.value(query.record().indexOf("ID")).toInt());
                users.push_back(admin);
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
                users.push_back(person);
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
                users.push_back(company);
            }
        }
    }
    else{
        qDebug() << "Error in fetching users. Error code: " << query.lastError() << endl;
        vector<UserBase> users;
        return users;
    }
    return users;
}

vector<Administrator> UserDAO::fetchAdminsFromDB(){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        vector<Administrator> admins;
        return admins;
    }

    QSqlQuery query(db);
    vector<Administrator> admins;

    query.prepare("SELECT * from users where TYPE=0");

    if(query.exec()){
        while(query.next()){
            Administrator admin = Administrator(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                                                query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
            admin.setUserID(query.value(query.record().indexOf("ID")).toInt());
            admins.push_back(admin);
        }
    }
    else{
        qDebug() << "Error in fetching administrators. Error code: " << query.lastError() << endl;
        vector<Administrator> admins;
        return admins;
    }
    return admins;
}

vector<Person> UserDAO::fetchPersonsFromDB(){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        vector<Person> persons;
        return persons;
    }

    QSqlQuery query(db);
    vector<Person> persons;

    query.prepare("SELECT * from users where TYPE=1");

    if(query.exec()){
        while(query.next()){
            Person person = Person(query.value(query.record().indexOf("USERNAME")).toString().toLocal8Bit().constData(),
                    query.value(query.record().indexOf("PASSWORD")).toString().toLocal8Bit().constData());
            person.setUserID(query.value(query.record().indexOf("ID")).toInt());
            person.setAfm(query.value(query.record().indexOf("AFM")).toString().toLocal8Bit().constData());
            person.setPhoneNumber(query.value(query.record().indexOf("PHONE")).toString().toLocal8Bit().constData());
            person.setAddress(query.value(query.record().indexOf("ADDRESS")).toString().toLocal8Bit().constData());
            person.setName(query.value(query.record().indexOf("NAME")).toString().toLocal8Bit().constData());
            person.setSurname(query.value(query.record().indexOf("SURNAME")).toString().toLocal8Bit().constData());
            person.setIdentity(query.value(query.record().indexOf("IDENTITY")).toString().toLocal8Bit().constData());
            persons.push_back(person);
        }
    }
    else{
        qDebug() << "Error in fetching persons. Error code: " << query.lastError() << endl;
        vector<Person> persons;
        return persons;
    }
    return persons;
}

vector<Company> UserDAO::fetchCompaniesFromDB(){
    if (!db.open()) {
        qDebug() << "Invalid or unset database.";
        vector<Company> companies;
        return companies;
    }

    QSqlQuery query(db);
    vector<Company> companies;

    query.prepare("SELECT * from users where TYPE=2");

    if(query.exec()){
        while(query.next()){
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
            companies.push_back(company);
        }
    }
    else{
        qDebug() << "Error in fetching companies. Error code: " << query.lastError() << endl;
        vector<Company> companies;
        return companies;
    }
    return companies;
}
