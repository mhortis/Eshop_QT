#pragma once
#include "stdafx.h"
#include "UserBase.h"
#include "Customer.h"
#include "Person.h"
#include "Company.h"
#include "Administrator.h"
#include "QtSql/QtSql"

class UserDAO
{
public:
    UserDAO(QSqlDatabase database);
	int insertPersonInDB(Person cust);
	int insertCompanyInDB(Company comp);
	int insertAdminInDB(Administrator admin);
	int removeUserFromDB(int userID);
	UserBase fetchUserByIDFromDB(int userID);
	vector<UserBase> fetchUsersFromDB();
	vector<Customer> fetchCustomersFromDB();
	vector<Person> fetchPersonsFromDB();
	vector<Company> fetchCompanyFromDB();
	vector<Administrator> fetchAdminsFromDB();

private:
    QSqlDatabase db;
};
