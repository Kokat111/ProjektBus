#include"Bus.h"
#include"Ticket.h"
#include"User.h"
#include"SqlManage.h"

SqlManage db;
Bus bus1;
Ticket ticket1;

bool CapitallLetter(string& tekst) {//funkcja do sprawdzania czy w tekscie jest wielka litera
    for (char c : tekst) {
        if (isupper(c)) {
            return false;
        }
    }
    return true;
}

void registe() { //funkcja do rejestracji
    string reglogin, regpassword, regpassword2;
    cout << "Podaj login: "; getline(cin, reglogin);
    cout << "Podaj haslo: "; getline(cin, regpassword);
    cout << "Powtorz haslo: "; getline(cin, regpassword2);
    string sql1 = "SELECT * FROM UserData WHERE UserName='" + reglogin + "'";
    UserData* loginData = db.getUser(sql1.c_str());
    if (loginData != NULL) {
        cout << "urzytkownik juz istnieje";
        cout << "Podaj login: "; getline(cin, reglogin);
        cout << "Podaj haslo: "; getline(cin, regpassword);
        cout << "Powtorz haslo: "; getline(cin, regpassword2);
        string sql1 = "SELECT * FROM UserData WHERE UserName='" + reglogin + "'";
        UserData* loginData = db.getUser(sql1.c_str());
    }
    else {
        if (regpassword != regpassword2 || CapitallLetter(regpassword)) {
            if (CapitallLetter(regpassword)) {
                cout << "Brak wielkiej litery" << endl;
                cout << "Podaj login: "; getline(cin, reglogin);
                cout << "Podaj haslo: "; cin >> regpassword;
                cout << "Powtorz haslo: "; cin >> regpassword2;
            }
            if (regpassword != regpassword2) {
                cout << "Niezgodnosc powtorzonego hasla" << endl;
                cout << "Podaj login: "; getline(cin, reglogin);
                cout << "Podaj haslo: "; cin >> regpassword;
                cout << "Powtorz haslo: "; cin >> regpassword2;
            }
        }
        string sql1 = "INSERT INTO UserData (UserName, Password, Money) VALUES ( '"+ reglogin +"', '"+regpassword+"',0);";
        db.sqlExecute(sql1.c_str());
        cout << "dziala";
    }
    
    User user1(reglogin, regpassword, 0);
    user1.info();
}


void login() { //Funkcja do logowania 
    string login, password;
    cout << "Podaj login: "; getline(cin, login);
    cout << "Podaj haslo: "; getline(cin, password);
    string sql1 = "SELECT * FROM UserData WHERE UserName='"+login+"'";
    UserData* loginData = db.getUser(sql1.c_str());
    if (loginData != NULL) {
        if (password == loginData->Password) {
            cout << "login udany"<<endl;
            User user1(login, password, 0);
            user1.info();
        }
    }
    else
    {
        cout << "login nie udany" << endl;
        cout << "Podaj login: "; getline(cin, login);
        cout << "Podaj haslo: "; getline(cin, password);
        string sql1 = "SELECT * FROM UserData WHERE UserName='" + login + "'";
        UserData* loginData = db.getUser(sql1.c_str());
    }
}

int main() {

    string sql1 = "SELECT * FROM UserData WHERE UserName='ewe'";
    UserData* loginData = db.getUser(sql1.c_str());
    
    //login();
    registe();

    bus1.info();
    ticket1.info();  
    return 0;
}