#include "stdafx.h"
#include "Order.h"
#include <cstring>
char* Order::getOrderNumber() {
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

char* Order::getOrderStatus() {
	return this->orderStatus;
}

void Order::setOrderNumber(char* orderNumber) {
    this->orderNumber = new char[strlen(orderNumber) + 1];
	strcpy(this->orderNumber, orderNumber);
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

void Order::setOrderStatus(char* orderStatus) {
	this->orderStatus = new char[strlen(orderStatus) + 1];
	strcpy(this->orderStatus, orderStatus);
}
