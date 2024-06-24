#include "SqlManage.h"

SqlManage::SqlManage() {
    int rc = sqlite3_open("Data.db", &this->db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "Opened database successfully" << std::endl;
    }
}

UserData* SqlManage::getUser(const char* sql){
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(this->db) << std::endl;
        return NULL;
    }

    UserData* userCurrent = NULL;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char* id = sqlite3_column_text(stmt, 0);
        const unsigned char* userName = sqlite3_column_text(stmt, 1);
        const unsigned char* password = sqlite3_column_text(stmt, 2);
        const unsigned char* money = sqlite3_column_text(stmt, 3);
        auto* user = new UserData;
        user->id = reinterpret_cast<const char*>(id);
        user->UserName = reinterpret_cast<const char*>(userName);
        user->Password = reinterpret_cast<const char*>(password);
        user->Money = reinterpret_cast<const char*>(password);
        user->next = NULL;

        if (userCurrent == NULL) {
            userCurrent = user;
        }
    }

    if (rc != SQLITE_DONE) {
        cout << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);

    return userCurrent;
}

void SqlManage::retriveData(string select, string from, string where) {
    sqlite3_stmt* stmt;
    char* messageError;
    string sql = "SELECT " + select + " FROM " + from + " WHERE " + where + ";";
    int exit = sqlite3_open("Data.db",&this->db);
    exit = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, NULL);
    if (exit != SQLITE_OK) {

        cerr << "Error in selectData function." << endl;
    }
    else {
        while (exit = sqlite3_step(stmt) == SQLITE_ROW)
        {
        }
    }
}

void SqlManage::sqlExecute(const char* sql) {

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(this->db) << std::endl;   
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    }
    if (rc != SQLITE_DONE) {
        cout << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_finalize(stmt);
}