#include <iostream>
#include "DBWorker.h"
#include "Exceptions.h"

using namespace std;


int testDBWorker() {
    string sql = "SELECT * from person;";
    DBWorker *worker = DBWorker::getInstance();
    auto result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }

    result.clear();
    vector<vector<string> >().swap(result);

    sql = "INSERT INTO person (name, birth_date, sex) VALUES ('Test Name', '1980-05-31', 'Female');";
    result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "inserted row" << endl;

    result.clear();
    vector<vector<string> >().swap(result);

    string maxID = worker->execute("SELECT max(id) FROM person;")[0][0];

    sql = "DELETE FROM person WHERE id = " + maxID + ";";
    result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "deleted row" << endl;


    result.clear();
    vector<vector<string> >().swap(result);


    delete worker;

    return 0;
}


int runTests() {
    testDBWorker();
    return 0;
}
