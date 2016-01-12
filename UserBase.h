#pragma once
using namespace std;

class UserBase {
public:
	UserBase();
    UserBase(string username, string password);
	int getUserID();
    string getUsername();
    string getPassword();
	void setUserID(int userID);
    void setUsername(string username);
    void setPassword(string password);
private:
	int userID;
    string username;
    string password;
};
