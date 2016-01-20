#ifndef NEWORDER_H
#define NEWORDER_H

#include <QDialog>
#include "dbconnection.h"
#include "Order.h"
#include "UserDAO.h"
#include "cart.h"
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
    void on_cancelOrder_clicked();
    void on_placeOrder_clicked();

private:
    Ui::NewOrder *ui;
    QSqlDatabase m_db;
    Order order;
    Cart cart;
    map <ProductBase,int> cartMap;
};

#endif // NEWORDER_H
