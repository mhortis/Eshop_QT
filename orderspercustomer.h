#ifndef ORDERSPERCUSTOMER_H
#define ORDERSPERCUSTOMER_H

#include <QDialog>
#include "dbconnection.h"
#include "OrderDAO.h"
#include "orderslistandupdate.h"

namespace Ui {
class OrdersPerCustomer;
}

class OrdersPerCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit OrdersPerCustomer(QWidget *parent = 0);
    void setCustomers(vector<int> customers);
    void showCustomers();
    ~OrdersPerCustomer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OrdersPerCustomer *ui;
    vector<int> customers;
    QSqlDatabase m_db;
};

#endif // ORDERSPERCUSTOMER_H
