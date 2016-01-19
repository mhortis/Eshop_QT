#ifndef ORDERSLISTANDUPDATE_H
#define ORDERSLISTANDUPDATE_H

#include <QDialog>
#include "dbconnection.h"
#include "OrderDAO.h"
#include <QMessageBox>

namespace Ui {
class OrdersListAndUpdate;
}

class OrdersListAndUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit OrdersListAndUpdate(QWidget *parent = 0);
    void setOrders(vector<Order>);
    void showOrders();
    ~OrdersListAndUpdate();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::OrdersListAndUpdate *ui;
    vector<Order> orders;
    QSqlDatabase m_db;
};

#endif // ORDERSLISTANDUPDATE_H
