#pragma once
#include "ProductBase.h"

class Availability
{
public:
	Availability();
	Availability(ProductBase product, int quantity);
	int getQuantity();
	ProductBase getProduct() const;
	bool operator== (const Availability &p2) const;
	bool operator< (const Availability &p2) const;
	bool operator> (const Availability &p2) const;
private:
	ProductBase product;
	int quantity;
};