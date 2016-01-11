#include "stdafx.h"
#include "UserBase.h"

UserBase::UserBase() {
}

UserBase::UserBase(string username, string password) {
	this->username = username;
	this->password = password;
}

int UserBase::getUserID() {
	return userID;
}

string UserBase::getUsername() {
	return username;
}

string UserBase::getPassword() {
	return password;
}

void UserBase::setUserID(int userID) {
	this->userID = userID;
}

void UserBase::setUsername(const char* username) {
    this->username = string(username);
}

void UserBase::setPassword(const char* password) {
    this->password = string(password);
}
