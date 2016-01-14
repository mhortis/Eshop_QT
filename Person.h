#pragma once
#include "Customer.h"
#include "Order.h"

class Person : public Customer
{
public:
    Person();
    Person(const char* username, const char* password);
    int getType();
    string getName();
    string getSurname();
    string getIdentity();
    void setName(const char* name);
    void setSurname(const char* surname);
    void setIdentity(const char* identity);
private:
    string name;
    string surname;
    string identity;
};
