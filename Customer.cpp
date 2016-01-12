#include "stdafx.h"
#include "Customer.h"

Customer::Customer() {
}

Customer::Customer(string username, string password) : UserBase(username, password) {
}

string Customer::getAfm() {
	return this->afm;
}

string Customer::getPhoneNumber() {
	return this->phoneNumber;
}

string Customer::getAddress() {
	return this->address;
}

void Customer::setAfm(string afm) {
    this->afm = afm;
}

void Customer::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::setAddress(string address) {
    this->address = address;
}

void Customer::addProductToCart(ProductBase product, int quantity) {
	for (map<ProductBase, int>::iterator mapIter = this->cart.begin(); mapIter != this->cart.end(); mapIter++) {
		ProductBase cur = mapIter->first;
		if (cur.getSerial() == product.getSerial()) {
			mapIter->second += quantity;
			return;
		}
	}
	this->cart.insert(pair<ProductBase, int>(product, quantity));
}

void Customer::removeProductFromCart(ProductBase product) {
	for (map<ProductBase, int>::iterator mapIter = this->cart.begin(); mapIter != this->cart.end(); mapIter++) {
		ProductBase cur = mapIter->first;
		if (cur.getSerial() == product.getSerial()) {
			this->cart.erase(mapIter);
			break;
		}
	}
}

void Customer::updateProductItemsInCart(ProductBase product, int newQuantity) {
	for (map<ProductBase, int>::iterator mapIter = this->cart.begin(); mapIter != this->cart.end(); mapIter++) {
		ProductBase cur = mapIter->first;
		if (cur.getSerial() == product.getSerial()) {
			mapIter->second = newQuantity;
			return;
		}
	}
	this->cart.insert(pair<ProductBase, int>(product, newQuantity));
}
