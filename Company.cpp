#include "stdafx.h"
#include "Company.h"

Company::Company(string username, string password) : Customer(username, password) {
}

string Company::getCompanyName()
{
	return this->companyName;
}

string Company::getResponsibleName()
{
	return this->responsibleName;
}

string Company::getResponsibleSurname()
{
	return this->responsibleSurname;
}

double Company::getDiscount()
{
	return this->discount;
}

string Company::getFax()
{
	return this->fax;
}

void Company::setCompanyName(string companyName)
{
    this->companyName = companyName;
}

void Company::setResponsibleName(string responsibleName)
{
    this->responsibleName = responsibleName;
}

void Company::setResponsibleSurname(string responsibleSurname)
{
    this->responsibleSurname = responsibleSurname;
}

void Company::setDiscount(double discount)
{
	this->discount = discount;
}

void Company::setFax(string fax)
{
    this->fax = fax;
}

Order Company::placeOrder()
{
	return Order();
}

