#pragma once
#include "Libs.h"

class User {
    //int id;
    double Balance;
    string Username;
    string Password;

public:
    User(string Usernam = "adas123", string Passwor = "maslo", double Balanc = 1.37);
    void info();
};