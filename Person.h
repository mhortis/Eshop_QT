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
    void setName(string name);
    void setSurname(string surname);
    void setIdentity(string identity);
	Order placeOrder();
private:
    string name;
    string surname;
    string identity;
};
