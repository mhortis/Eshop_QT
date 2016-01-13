#pragma once
using namespace std;

class UserBase {
public:
	UserBase();
    UserBase(const char* username, const char* password);
	int getUserID();
    string getUsername();
    string getPassword();
    virtual int getType()
    {return type;}
	void setUserID(int userID);
    void setType(int type);
    void setUsername(const char* username);
    void setPassword(const char* password);
private:
	int userID;
    int type;
    string username;
    string password;
};
