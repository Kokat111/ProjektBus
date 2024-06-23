#include "User.h"

void User::info() {
    cout << Username << ' ' << Password << ' ' << "Saldo konta : " << Balance << "zl" << endl;
}

User::User(string Username, string Password, double Balance) : Balance(Balance), Username(Username), Password(Password) {}