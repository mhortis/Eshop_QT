#pragma once
#include "Customer.h"
#include "Order.h"

class Company : public Customer
{
public:
    Company(string username, string password);
    string getCompanyName();
    string getResponsibleName();
    string getResponsibleSurname();
	double getDiscount();
    string getFax();
    void setCompanyName(const char* companyName);
    void setResponsibleName(const char* responsibleName);
    void setResponsibleSurname(const char* responsibleSurname);
	void setDiscount(double discount);
    void setFax(const char* fax);
	Order placeOrder();
private:
    string companyName;
    string responsibleName;
    string responsibleSurname;
	double discount;
    string fax;
};

