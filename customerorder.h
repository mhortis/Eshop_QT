#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <QDialog>
#include "dbconnection.h"
#include "OrderDAO.h"

namespace Ui {
class CustomerOrder;
}

class CustomerOrder : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerOrder(QWidget *parent = 0);
    void setOrder(Order order);
    void showOrderItems();
    ~CustomerOrder();

private:
    Ui::CustomerOrder *ui;
    QSqlDatabase m_db;
    Order order;
};

#endif // CUSTOMERORDER_H
