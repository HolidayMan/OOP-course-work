#include <iostream>
#include "DBWorker.h"
#include "Exceptions.h"
#include "models/DwellingManager.h"

using namespace std;


int testDBWorker() {
    cout << "Test DBWorker" << endl;
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


    cout << "\n\n\n\n";

    return 0;
}

int testDwellingManager() {
    cout << "Test DwellingManager" << "\n\n";

    cout << "getList()" << endl;
    for (auto dwelling: DwellingManager().getList()) {
        cout << dwelling->pk << " " << dwelling->address << " " << dwelling->rooms << endl;
    }
    cout << endl;
    return 0;
}


int runTests() {
    testDBWorker();
    testDwellingManager();
    return 0;
}
