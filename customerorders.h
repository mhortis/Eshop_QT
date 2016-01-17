#ifndef CUSTOMERORDERS_H
#define CUSTOMERORDERS_H

#include <QDialog>
#include "dbconnection.h"
#include "OrderDAO.h"
#include "customerorder.h"
#include <QMessageBox>

namespace Ui {
class CustomerOrders;
}

class CustomerOrders : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerOrders(QWidget *parent = 0);
    void setOrders(vector<Order> orders);
    void showOrders();
    ~CustomerOrders();

private slots:
    void on_table_doubleClicked(const QModelIndex &index);

    void on_cancelOrder_clicked();

private:
    Ui::CustomerOrders *ui;
    QSqlDatabase m_db;
    vector<Order> orders;
};

#endif // CUSTOMERORDERS_H
