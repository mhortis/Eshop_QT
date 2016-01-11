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

void Company::setCompanyName(const char* companyName)
{
    this->companyName = string(companyName);
}

void Company::setResponsibleName(const char* responsibleName)
{
    this->responsibleName = string(responsibleName);
}

void Company::setResponsibleSurname(const char* responsibleSurname)
{
    this->responsibleSurname = string(responsibleSurname);
}

void Company::setDiscount(double discount)
{
	this->discount = discount;
}

void Company::setFax(const char* fax)
{
    this->fax = string(fax);
}

Order Company::placeOrder()
{
	return Order();
}

