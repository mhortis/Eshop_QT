#ifndef SHOWCART_H
#define SHOWCART_H

#include <QDialog>
#include "DBConnection.h"
#include <QSqlDatabase>
#include "cart.h"

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
    map<int,int> cart;
};

#endif // SHOWCART_H
