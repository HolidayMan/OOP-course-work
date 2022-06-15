#include "DwellingManager.h"

#include <iostream>
#include <vector>
#include "Dwelling.h"
#include "DwellingManager.h"
#include "../DBWorker.h"
#include <sstream>

using namespace std;

Dwelling* initDwellingWithPk(int pk, string address, int rooms) {
    auto* dwelling = new Dwelling(address, rooms);
    dwelling->pk = pk;
    return dwelling;
}

vector<Dwelling*> DwellingManager::getList() const {
    DBWorker* worker = DBWorker::getInstance();
    string query = "SELECT * FROM dwelling;";
    auto result = worker->execute(query);
    vector<Dwelling*> dwellings;
    for (auto row: result) {
        int id = stoi(row[0]);
        dwellings.push_back(initDwellingWithPk(id, row[1], stoi(row[2])));
    }
    return dwellings;
}

Dwelling* DwellingManager::get(int pk) const {
    DBWorker* worker = DBWorker::getInstance();
    string query = "SELECT * FROM dwelling WHERE id=" + to_string(pk) + ";";
    auto result = worker->execute(query)[0];
    return initDwellingWithPk(stoi(result[0]), result[1], stoi(result[2]));

}

vector<Dwelling*> DwellingManager::filter(Filter* condition) const {
    std::stringstream ss;
    ss << "SELECT * FROM dwelling WHERE " << condition->getRepresentation("");

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(ss.str());
    vector<Dwelling*> dwellings;
    for (auto row: result) {
        int id = stoi(row[0]);
        dwellings.push_back(initDwellingWithPk(id, row[1], stoi(row[2])));
    }

    return dwellings;
}

Dwelling* DwellingManager::save(const Dwelling* model) const {
    string query = "INSERT INTO dwelling (address, rooms) VALUES ('" + model->address + "', '" + to_string(model->rooms) + "');";
    bool create = true;
    if (model->pk != 0) {
        query = "UPDATE dwelling SET address='" + model->address + "', rooms=" + to_string(model->rooms) + " WHERE id=" +
                to_string(model->pk) + ";";
        create = false;
    }
    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(query);

    if (!create) {
        return get(model->pk);
    }


    query = "SELECT MAX(id) FROM dwelling;";
    auto id = stoi(worker->execute(query)[0][0]);
    return get(id);

}

int DwellingManager::remove(const Dwelling *model) const {
    if (!model->pk) {
        return 0;
    }
    DBWorker* worker = DBWorker::getInstance();
    string query = "DELETE FROM dwelling WHERE id=" + to_string(model->pk) + ";";
    worker->execute(query)[0];
    return 0;
}

