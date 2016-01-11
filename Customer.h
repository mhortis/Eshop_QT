#pragma once
#include "UserBase.h"
#include "ProductBase.h"

class Customer : public UserBase
{
public:
	Customer();
    Customer(string username, string password);
    string getAfm();
    string getPhoneNumber();
    string getAddress();
    void setAfm(const char* afm);
    void setPhoneNumber(const char* phoneNumber);
    void setAddress(const char* address);
	void addProductToCart(ProductBase product, int quantity);
	void updateProductItemsInCart(ProductBase product, int newQuantity);
	void removeProductFromCart(ProductBase product);
private:
    string afm;
    string phoneNumber;
    string address;
	map<ProductBase, int> cart;
};

