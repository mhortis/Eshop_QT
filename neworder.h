#ifndef NEWORDER_H
#define NEWORDER_H

#include <QDialog>
#include "dbconnection.h"
#include "Order.h"
#include "UserDAO.h"

namespace Ui {
class NewOrder;
}

class NewOrder : public QDialog
{
    Q_OBJECT

public:
    explicit NewOrder(QWidget *parent = 0);
    void setOrder(Order order);
    void showOrder();
    ~NewOrder();

private:
    Ui::NewOrder *ui;
    QSqlDatabase m_db;
    Order order;
};

#endif // NEWORDER_H
