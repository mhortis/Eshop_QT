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
    void setCompanyName(string companyName);
    void setResponsibleName(string responsibleName);
    void setResponsibleSurname(string responsibleSurname);
	void setDiscount(double discount);
    void setFax(string fax);
	Order placeOrder();
private:
    string companyName;
    string responsibleName;
    string responsibleSurname;
	double discount;
    string fax;
};

