#include"Bus.h"
#include"Ticket.h"
#include"User.h"
#include"SqlManage.h"

void registe() {
    string reglogin, regpassword, regpassword2;
    cout << "Podaj login: "; cin >> reglogin;
    cout << "Podaj haslo: "; cin >> regpassword;
    cout << "Powtorz haslo: "; cin >> regpassword2;
    while (regpassword != regpassword2) {
        cout << "ROZNE HASLA" << endl;
        cout << "Podaj haslo: "; cin >> regpassword;
        cout << "Powtorz haslo: "; cin >> regpassword2;
    }
    User user1(reglogin, regpassword, 0);
    user1.info();
}

int main() {
    SqlManage db;
    Bus bus1;
    Ticket ticket1;

    string sql1 = "SELECT * FROM UserData WHERE UserName='admin'";
    UserData* loginData = db.getPassword(sql1.c_str());
    

    registe();

    bus1.info();
    ticket1.info();
    return 0;
}