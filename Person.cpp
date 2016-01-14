#include "stdafx.h"
#include "Person.h"

Person::Person(){
}

Person::Person(const char* username, const char* password) : Customer(username, password) {
    setType(1);
}

int Person::getType(){
    return 1;
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
