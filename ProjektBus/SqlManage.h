#pragma once
#include "Libs.h"
struct UserData {
    string id;
    string UserName;
    string Password;
    string Money;
};
struct TicketData {
    string id;
    string stacjaPocz;
    string stacjaKonc;
    string cena;
    string godzPrzyjazdu;
    string godzOdjazdu;
    UserData* next;
};
struct Booking
{
    string id;
    string User_id;
    string Ticket_id;
};
class SqlManage
{
public:
    SqlManage();//konstruktor inicjujący baze danych 
    UserData* getUser(const char* sql); //funkcja wpisująca dane usera do struktury
    void retriveData(string select, string from, string where);//funkcja do testowania zapytania SELECT
    void sqlExecute(const char* sql);//funkcja wykonująca podane polecenie sql

      
private:
    sqlite3* db;
};

