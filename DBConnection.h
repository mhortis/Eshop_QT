#pragma once
#include "QtSql/QtSql"

class DBConnection
{
public:
    DBConnection(QSqlDatabase newDB);
    QSqlDatabase getDB();
    void setDB(QSqlDatabase newDB);
    void setDBName(QString dbName);
private:
    QSqlDatabase db;
};
