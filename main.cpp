#include "mainwindow.h"
#include <QApplication>
#include "QtSql/QtSql"
#include "ProductDAO.h"
#include "UserDAO.h"
#include "OrderDAO.h"
#include "DBConnection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase m_db;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir = QDir::currentPath();
    QString dbPath =  dir.canonicalPath() + "/eshop.db";
    m_db.setDatabaseName( dbPath);
    DBConnection::getInstance().setDB(m_db);

    if (!DBConnection::getInstance().getDB().isOpen())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    MainWindow w;
    w.show();

    return a.exec();
}
