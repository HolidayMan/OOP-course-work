#include "DBWorker.h"
#include "Constants.h"
#include "sqlite3.h"
#include "Exceptions.h"

DBWorker* DBWorker::singleton = nullptr;

DBWorker* DBWorker::getInstance() {
    if(singleton==nullptr){
        singleton = new DBWorker();
    }
    return singleton;
}

DBWorker::DBWorker() {
    int rc = sqlite3_open(DB_NAME.c_str(), &cursor);
    if (rc) {
        throw Exception("Cannot open database. Check if DB file is in main project folder.");
    }
}

vector<vector<string>> DBWorker::execute(const string& query) {
    auto* result = new vector<vector<string>>;
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(cursor, query.c_str(), callback, (void*)result, &zErrMsg);

    if( rc != SQLITE_OK ) {
        throw Exception(string("SQL error: ") + zErrMsg);
    }

    return *result;
}

int DBWorker::callback(void *data, int rowsCount, char **values, char **colNames) {
    auto *results = (vector<vector<string>>*)data;
    auto* result = new vector<string>;
    for (int i = 0; i < rowsCount; i++) {
        result->emplace_back(values[i] ? values[i] : "NULL");
    }
    results->push_back(*result);
    return 0;
}

sqlite3 *DBWorker::getCursor() {
    return cursor;
}

DBWorker::~DBWorker() {
    sqlite3_close(cursor);
}
