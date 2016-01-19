#ifndef ORDERSPERSTATUS_H
#define ORDERSPERSTATUS_H

#include <QDialog>
#include <QMessageBox>
#include "dbconnection.h"
#include "OrderDAO.h"
#include "orderslistandupdate.h"

namespace Ui {
class OrdersPerStatus;
}

class OrdersPerStatus : public QDialog
{
    Q_OBJECT

public:
    explicit OrdersPerStatus(QWidget *parent = 0);
    ~OrdersPerStatus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OrdersPerStatus *ui;
    QSqlDatabase m_db;
};

#endif // ORDERSPERSTATUS_H
