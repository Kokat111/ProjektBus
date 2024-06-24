#pragma once
#include "Libs.h"
struct UserData {
    string id;
    string UserName;
    string Password;
    string Money;
    UserData* next;
};
class SqlManage
{
public:
    SqlManage();//konstruktor inicjujący baze danych 
    UserData* getUser(const char* sql); //funkcja wpisująca dane usera do struktury
    void retriveData(string select, string from, string where);//funkcja do testowania zapytania SELECT
    UserData* insertUser(const char* sql,string userName, string Password);

      
private:
    sqlite3* db;
};

