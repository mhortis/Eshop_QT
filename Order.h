#pragma once
#include "ProductBase.h"
#include "Customer.h"

class Order
{
public:
	char* getOrderNumber();
	Customer getOrderBuyer();
	map<ProductBase, int> getOrderItems();
	double getOrderCost();
	char* getOrderStatus();
	void setOrderNumber(char* orderNumber);
	void setOrderBuyer(Customer orderBuyer);
	void setOrderItems(map<ProductBase, int> orderItems);
	void setOrderCost(double orderCost);
	void setOrderStatus(char* orderStatus);
private:
	char* orderNumber;
	Customer orderBuyer;
	map<ProductBase, int> orderItems;
	double orderCost;
	char* orderStatus;
};