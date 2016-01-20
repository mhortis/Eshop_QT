#pragma once
#include "Order.h"
#include "Customer.h"
#include "QtSql/QtSql"

class OrderDAO
{
public:
    OrderDAO(QSqlDatabase database);
    Order insertOrderInDB(Customer cust, map<ProductBase, int> cart);
    Order insertOrderInDB(Order order);
    Order fetchOrderByIDFromDB(int orderID);
    vector<Order> fetchOrdersByStatus(string status);
    vector<Order> fetchOrderByCustomer(int customerID);
    vector<int> fetchCustomerIDsWithOrders();
    int updateOrderBuyerInDB(int orderID, int customerID);
    int updateOrderStatusInDB(int orderID, string newOrderStatus);
    int removeOrderFromDB(int orderID);
    vector<double> fetchAllOrderCost();
private:
    QSqlDatabase db;
};
