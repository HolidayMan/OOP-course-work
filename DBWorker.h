#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class DBWorker {
public:
    ~DBWorker();

    DBWorker(DBWorker &other) = delete;
    void operator=(const DBWorker &) = delete;

    sqlite3* getCursor();
    static DBWorker *getInstance();
    vector<vector<string>> execute(const string& query);

protected:
    DBWorker();
    static int callback(void *data, int rowsCount, char **values, char **colNames);
    static DBWorker* singleton;
    sqlite3 *cursor;
};
