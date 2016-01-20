#ifndef CUSTOMERPANEL_H
#define CUSTOMERPANEL_H

#include <QMainWindow>
#include "dbconnection.h"
#include "stdafx.h"
#include "Customer.h"
#include <QMessageBox>
#include "OrderDAO.h"
#include "neworder.h"
#include "customerorders.h"
#include "Customer.h"

namespace Ui {
class CustomerPanel;
}

class CustomerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerPanel(QWidget *parent = 0);
    void setCustomer(Customer cust);
    int getUserID();
    Customer getCustomer();
    ~CustomerPanel();

private slots:
    void on_actionLogout_triggered();
    int getPanelType();
    void on_actionList_Products_triggered();
    void on_actionView_Orders_triggered();
    void on_actionNew_Order_triggered();
    void on_actionShow_Cart_triggered();

private:
    Ui::CustomerPanel *ui;
    int panelType = 2;
    QSqlDatabase m_db;
    Customer customer;
};

#endif // CUSTOMERPANEL_H
