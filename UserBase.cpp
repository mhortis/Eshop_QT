#include "stdafx.h"
#include "UserBase.h"

UserBase::UserBase() {
}

UserBase::UserBase(const char* username, const char* password) {
    this->username = string(username);
    this->password = string(password);
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

void UserBase::setType(int type){
    this->type = type;
}

void UserBase::setUsername(const char* username) {
    this->username = string(username);
}

void UserBase::setPassword(const char* password) {
    this->password = string(password);
}
