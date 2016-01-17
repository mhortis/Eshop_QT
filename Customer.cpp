#include "stdafx.h"
#include "Customer.h"

Customer::Customer() {
}

Customer::Customer(const char* username, const char* password) : UserBase(username, password) {
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

map<ProductBase, int> Customer::getCart(){
    return this->cart;
}

void Customer::setAfm(const char* afm) {
    this->afm = string(afm);
}

void Customer::setPhoneNumber(const char* phoneNumber) {
    this->phoneNumber = string(phoneNumber);
}

void Customer::setAddress(const char* address) {
    this->address = string(address);
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
