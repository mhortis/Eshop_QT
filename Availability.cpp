#include "stdafx.h"
#include "Availability.h"

Availability::Availability() {
}

Availability::Availability(ProductBase product, int quantity){
	this->product = product;
	this->quantity = quantity;
}

int Availability::getQuantity() {
	return this->quantity;
}

ProductBase Availability::getProduct() const {
	return this->product;
}

bool Availability::operator==(const Availability &p2) const {
	return (this->getProduct() == p2.getProduct());
}

bool Availability::operator<(const Availability &p2) const {
	return (this->getProduct() < p2.getProduct());
}

bool Availability::operator>(const Availability &p2) const {
	return (this->getProduct() > p2.getProduct());
}