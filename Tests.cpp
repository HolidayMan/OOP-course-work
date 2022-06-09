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

    delete worker;

    result.clear();
    vector<vector<string> >().swap(result);
    return 0;
}


int runTests() {
    testDBWorker();
    return 0;
}
