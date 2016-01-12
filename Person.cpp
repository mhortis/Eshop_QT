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

void Person::setName(string name) {
    this->name = name;
}

void Person::setSurname(string surname) {
    this->surname = surname;
}

void Person::setIdentity(string identity) {
    this->identity = identity;
}

Order Person::placeOrder()
{
	return Order();
}

