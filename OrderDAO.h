#pragma once
#include "Order.h"
#include "Customer.h"
#include "QtSql/QtSql"

class OrderDAO
{
public:
    OrderDAO(QSqlDatabase database);
    Order insertOrderInDB(Customer cust, map<ProductBase, int> cart);
    Order fetchOrderByIDFromDB(int orderID);
    int updateOrderStatusInDB(int orderID, string newOrderStatus);
    int removeOrderFromDB(int orderID);
private:
    QSqlDatabase db;
};
