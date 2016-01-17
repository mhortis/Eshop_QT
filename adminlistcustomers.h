#ifndef ADMINLISTCUSTOMERS_H
#define ADMINLISTCUSTOMERS_H
#include <QDialog>
#include "UserBase.h"
#include "dbconnection.h"
#include "Person.h"
#include "Company.h"

namespace Ui {
class AdminListCustomers;
}

class AdminListCustomers : public QDialog
{
    Q_OBJECT

public:
    explicit AdminListCustomers(QWidget *parent = 0);
    ~AdminListCustomers();

private slots:
    void on_showPers_clicked();
    void on_showComp_clicked();

private:
    Ui::AdminListCustomers *ui;
    vector<UserBase> users;
    vector<Person> persons;
    vector<Company> companies;
    QSqlDatabase m_db;
};

#endif // ADMINLISTCUSTOMERS_H
