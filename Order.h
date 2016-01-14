#pragma once
#include "ProductBase.h"
#include "Customer.h"

class Order
{
public:
    int getOrderNumber();
	Customer getOrderBuyer();
	map<ProductBase, int> getOrderItems();
	double getOrderCost();
    string getOrderStatus();
    void setOrderNumber(int);
    void setOrderBuyer(Customer orderBuyer);
	void setOrderItems(map<ProductBase, int> orderItems);
	void setOrderCost(double orderCost);
    void setOrderStatus(const char* orderStatus);
private:
    int orderNumber;
	Customer orderBuyer;
	map<ProductBase, int> orderItems;
	double orderCost;
    string orderStatus;
};
