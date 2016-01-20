#ifndef NEWORDER_H
#define NEWORDER_H

#include <QDialog>
#include "dbconnection.h"
#include "UserDAO.h"
#include "OrderDAO.h"

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

private slots:
    void on_cancelButton_clicked();

    void on_placeOrderButton_clicked();

private:
    Ui::NewOrder *ui;
    QSqlDatabase m_db;
    Order order;
};

#endif // NEWORDER_H
