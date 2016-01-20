#pragma once
#include "UserBase.h"

class Administrator : public UserBase{
public:
    Administrator(const char* username, const char* password);
    int getType();
};
