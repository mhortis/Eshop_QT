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
    void setUsername(const char* username);
    void setPassword(const char* password);
private:
	int userID;
    string username;
    string password;
};
