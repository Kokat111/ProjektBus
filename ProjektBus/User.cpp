#include "User.h"

void User::info() {
    cout << Username << ' ' << Password << ' ' << "Saldo konta : " << Balance << "zl" << endl;
}

User::User(string Usernam , string Passwor, double Balanc) : Balance(Balanc), Username(Usernam), Password(Passwor) {}