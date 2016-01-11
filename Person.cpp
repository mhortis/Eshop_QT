#include "stdafx.h"
#include "Person.h"


Person::Person(string username, string password) : Customer(username, password) {
}

string Person::getName() {
	return this->name;
}

string Person::getSurname() {
	return this->surname;
}

string Person::getIdentity() {
	return this->identity;
}

void Person::setName(const char* name) {
    this->name = string(name);
}

void Person::setSurname(const char* surname) {
    this->surname = string(surname);
}

void Person::setIdentity(const char* identity) {
    this->identity = string(identity);
}

Order Person::placeOrder()
{
	return Order();
}

