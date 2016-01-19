#ifndef SHOWCART_H
#define SHOWCART_H
#include <QDialog>
#include "DBConnection.h"
#include <QSqlDatabase>
#include "cart.h"
#include "ProductBase.h"
#include "Customer.h"

namespace Ui {
class showCart;
}

class showCart : public QDialog
{
    Q_OBJECT

public:
    explicit showCart(QWidget *parent = 0);
    ~showCart();

private:
    Ui::showCart *ui;
    QSqlDatabase m_db;
    Cart cart;
    Customer customer;
};

#endif // SHOWCART_H
