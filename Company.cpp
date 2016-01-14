#include "stdafx.h"
#include "Company.h"

Company::Company(){
}

Company::Company(const char* username, const char* password) : Customer(username, password) {
    setType(2);
}

int Company::getType(){
    return 2;
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
