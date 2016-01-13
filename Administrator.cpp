#include "stdafx.h"
#include "Administrator.h"

Administrator::Administrator(const char* username, const char* password) : UserBase(username, password) {
    setType(0);
}

int Administrator::getType(){
    return 0;
}
