#include "stdafx.h"
#include "ProductBase.h"

ProductBase::ProductBase() {
}

int ProductBase::getSerial() const {
	return serial;
}

string ProductBase::getModel() {
	return model;
}

string ProductBase::getManufacturer() {
	return manufacturer;
}

string ProductBase::getPhotoUrl() {
	return photoUrl;
}

string ProductBase::getDescription() {
	return description;
}

double ProductBase::getPrice() {
	return price;
}

void ProductBase::setSerial(int serial) {
	this->serial = serial;
}

void ProductBase::setType(int type) {
	this->type = type;
}

void ProductBase::setModel(const char* model) {
    this->model = string(model);
}

void ProductBase::setManufacturer(const char* manufacturer) {
    this->manufacturer = string(manufacturer);
}

void ProductBase::setPhotoUrl(const char* photoUrl) {
    this->photoUrl = string(photoUrl);
}

void ProductBase::setDescription(const char* description) {
    this->description = string(description);
}

void ProductBase::setPrice(double price) {
	this->price = price;
}

bool ProductBase::operator==(const ProductBase &p2) const {
	return (this->getSerial() == p2.getSerial());
}

bool ProductBase::operator<(const ProductBase &p2) const {
	return (this->getSerial() < p2.getSerial());
}

bool ProductBase::operator>(const ProductBase &p2) const {
	return (this->getSerial() > p2.getSerial());
}
