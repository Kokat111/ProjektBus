#pragma once
#include "Libs.h"

class User {
    //int id;
    double Balance;
    string Username;
    string Password;

public:
    User(string Username = "usr154", string Password = "melancholY", double Balance = 1.37);
    void info();
};