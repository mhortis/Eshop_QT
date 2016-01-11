#pragma once
#include "Customer.h"
#include "Order.h"

class Person : public Customer
{
public:
    Person(string username, string password);
    string getName();
    string getSurname();
    string getIdentity();
    void setName(const char* name);
    void setSurname(const char* surname);
    void setIdentity(const char* identity);
	Order placeOrder();
private:
    string name;
    string surname;
    string identity;
};