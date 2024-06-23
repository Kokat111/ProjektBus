#pragma once
#include "Libs.h"
struct UserData {
    string id;
    string UserName;
    string Password;
    UserData* next;
};
class SqlManage
{
public:
    SqlManage();
    UserData* getPassword(const char* sql);
    void retriveData(string select, string from, string where);

      
private:
    sqlite3* db;
};

