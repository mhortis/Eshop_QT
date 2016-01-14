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

void Order::setOrderStatus(const char* orderStatus) {
    this->orderStatus = string(orderStatus);
}
