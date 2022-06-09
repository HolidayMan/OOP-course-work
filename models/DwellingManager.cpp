#include "DwellingManager.h"

#include <iostream>
#include <vector>
#include "Dwelling.h"
#include "DwellingManager.h"
#include "../DBWorker.h"

using namespace std;


vector<Dwelling*> DwellingManager::getList() const {
    DBWorker* worker = DBWorker::getInstance();
    string query = "SELECT * FROM dwelling;";
    auto result = worker->execute(query);
    vector<Dwelling*> dwellings;
    for (auto row: result) {
        int id = stoi(row[0]);
        auto* dwelling = new Dwelling(row[1], stoi(row[2]));
        dwelling->pk = stoi(row[0]);
        dwellings.push_back(dwelling);
    }
    return dwellings;
}

Dwelling* DwellingManager::get() const {
    // TODO: implement
}

vector<Dwelling*> DwellingManager::filter() const {
    // TODO: implement
}

Dwelling* DwellingManager::save(const Dwelling* model) const {
    // TODO: implement
}

