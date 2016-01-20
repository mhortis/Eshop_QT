#pragma once
#include "UserBase.h"
#include "ProductBase.h"

class Customer : public UserBase
{
public:
	Customer();
    Customer(const char* username, const char* password);
    string getAfm();
    string getPhoneNumber();
    string getAddress();
    map<ProductBase, int> getCart();
    void setAfm(const char* afm);
    void setPhoneNumber(const char* phoneNumber);
    void setAddress(const char* address);
    void addProductToCart(ProductBase product, int quantity);
	void updateProductItemsInCart(ProductBase product, int newQuantity);
    void setCart(map<ProductBase, int> cart);
	void removeProductFromCart(ProductBase product);
private:
    string afm;
    string phoneNumber;
    string address;
	map<ProductBase, int> cart;
};
