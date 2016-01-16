#pragma once
#include "QtSql/QtSql"

class DBConnection
{
public:
    static DBConnection& getInstance(){
        static DBConnection instance;
        return instance;
    }
    QSqlDatabase getDB();
    void setDB(QSqlDatabase newDB);
    void setDBName(QString dbName);
private:
    QSqlDatabase db;
};
