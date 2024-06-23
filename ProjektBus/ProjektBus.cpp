#include"Bus.h"
#include"Ticket.h"
#include"User.h"

bool CapitallLetter(string& tekst) {
    for (char c : tekst) {
        if (isupper(c)) {
            return false;
        }
    }
    return true;
}

void registe() {
    string reglogin, regpassword, regpassword2;
    cout << "Podaj login: "; getline(cin, reglogin);
    cout << "Podaj haslo: "; getline(cin, regpassword);
    cout << "Powtorz haslo: "; getline(cin, regpassword2);
    while (regpassword != regpassword2 || CapitallLetter(regpassword)) {
        if (CapitallLetter(regpassword) || CapitallLetter(regpassword2)) {
            cout << "Brak wielkiej litery" << endl;
        }
        if (regpassword != regpassword2) {
            cout << "Niezgodnosc powtorzonego hasla" << endl;
        }
        cout << "Podaj haslo: "; cin >> regpassword;
        cout << "Powtorz haslo: "; cin >> regpassword2;
    }
    User user1(reglogin, regpassword, 0);
    user1.info();
}

int main() {
    Bus bus1;
    Ticket ticket1;

    registe();

    bus1.info();
    ticket1.info();
    return 0;
}