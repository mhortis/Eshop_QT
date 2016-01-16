#include "DBConnection.h"

QSqlDatabase DBConnection::getDB(){
    return this->db;
}

void DBConnection::setDB(QSqlDatabase newDB){
    if(this->db.isOpen())
        this->db.close();

    this->db = newDB;
    this->db.open();
}

void DBConnection::setDBName(QString dbName){
    if(this->db.isOpen())
        this->db.close();

    this->db.setDatabaseName(dbName);
    this->db.open();
}
