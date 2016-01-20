#ifndef SHOWCART_H
#define SHOWCART_H
#include <QDialog>
#include "DBConnection.h"
#include <QSqlDatabase>
#include "cart.h"
#include "ProductBase.h"
#include "Customer.h"
#include "OrderDAO.h"
#include <QMessageBox>

namespace Ui {
class showCart;
}

class showCart : public QDialog
{
    Q_OBJECT

public:
    explicit showCart(QWidget *parent = 0);
    ~showCart();

private slots:

    void on_pushButton_clicked();

private:
    Ui::showCart *ui;
    QSqlDatabase m_db;
    Customer customer;
};

#endif // SHOWCART_H
