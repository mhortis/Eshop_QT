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
    int userExistsInDB(string username, string password);
	UserBase fetchUserByIDFromDB(int userID);
    UserBase fetchUserByUsernamePwdFromDB(string username, string password);
    Person fetchPersonDetailsFromDB(int userID);
    Company fetchCompanyDetailsFromDB(int companyID);
	vector<UserBase> fetchUsersFromDB();
    vector<Person> fetchPersonsFromDB();
    vector<Company> fetchCompaniesFromDB();
	vector<Administrator> fetchAdminsFromDB();

private:
    QSqlDatabase db;
};
