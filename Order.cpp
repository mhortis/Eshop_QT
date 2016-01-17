#include "stdafx.h"
#include "Order.h"

int Order::getOrderNumber() {
	return this->orderNumber;
}

Customer Order::getOrderBuyer() {
	return this->orderBuyer;
}

map<ProductBase, int> Order::getOrderItems() {
	return this->orderItems;
}

double Order::getOrderCost() {
	return this->orderCost;
}

string Order::getOrderStatus() {
	return this->orderStatus;
}

void Order::setOrderNumber(int orderNumber) {
    this->orderNumber = orderNumber;
}

void Order::setOrderBuyer(Customer orderBuyer) {
	this->orderBuyer = orderBuyer;
}

void Order::setOrderItems(map<ProductBase, int> orderItems) {
	this->orderItems = orderItems;
}

void Order::setOrderCost(double orderCost) {
    this->orderCost = orderCost;
}

void Order::setOrderCost(map<ProductBase, int> orderItems) {
    double cost = 0;
    for(map<ProductBase, int>::iterator iter = orderItems.begin(); iter != orderItems.end(); iter++){
        ProductBase cur = iter->first;
        int quantity = iter->second;
        double price = cur.getPrice() * quantity;
        cost += price;
    }
    this->orderCost = cost;
}

void Order::setOrderStatus(const char* orderStatus) {
    this->orderStatus = string(orderStatus);
}
