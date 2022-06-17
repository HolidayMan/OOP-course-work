#include <iostream>
#include <utility>
#include <vector>
#include "PersonManager.h"
#include "../DBWorker.h"
#include <boost/format.hpp>
#include <sstream>

using namespace std;

Person* initPersonWithPk(int pk, string _name, Date* _birthDate, string _sex, string _family) {
    auto* person = new Person(std::move(_name), _birthDate, std::move(_sex), std::move(_family));
    person->pk = pk;
    return person;
}

vector<Person*> PersonManager::getList() const {
    DBWorker* worker = DBWorker::getInstance();
    string query = "SELECT * FROM person;";
    auto result = worker->execute(query);
    vector<Person*> people;
    for (auto row: result) {
        int id = stoi(row[0]);
        people.push_back(initPersonWithPk(id, row[1], new Date(row[2]), row[3], row[4]));
    }
    return people;
}

Person* PersonManager::get(int pk) const {
    DBWorker* worker = DBWorker::getInstance();
    string query = "SELECT * FROM person WHERE id=" + to_string(pk) + ";";
    auto row = worker->execute(query)[0];
    return initPersonWithPk(stoi(row[0]), row[1], new Date(row[2]), row[3], row[4]);
}

vector<Person*> PersonManager::filter(Filter* condition) const {
    std::stringstream ss;
    ss << "SELECT * FROM person WHERE " << condition->getRepresentation("");

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(ss.str());
    vector<Person*> people;
    for (auto row: result) {
        int id = stoi(row[0]);
        people.push_back(initPersonWithPk(id, row[1], new Date(row[2]), row[3], row[4]));
    }

    return people;
}

Person* PersonManager::save(const Person* model) const {
    string query;
    if (model->family.empty()) {
        query = "INSERT INTO person (name, birth_date, sex) VALUES ('%s', '%s', '%s');";
        query = (boost::format(query) % model->name % model->birthDate->toRepresentation() % model->sex).str();
    } else {
        query = "INSERT INTO person (name, birth_date, sex, family) VALUES ('%s', '%s', '%s', '%s');";
        query = (boost::format(query) % model->name % model->birthDate->toRepresentation() % model->sex % model->family).str();
    }
    bool create = true;
    if (model->pk != 0) {
        if (model->family.empty()) {
            query = "UPDATE person SET name='%s', birth_date='%s', sex='%s' WHERE id=%d;";
            query = (boost::format(query) % model->name % model->birthDate->toRepresentation() % model->sex % model->pk).str();
        } else {
            query = "UPDATE person SET name='%s', birth_date='%s', sex='%s', family='%s' WHERE id=%d;";
            query = (boost::format(query) % model->name % model->birthDate->toRepresentation() % model->sex % model->family % model->pk).str();
        }
        create = false;
    }
    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(query);

    if (!create) {
        return get(model->pk);
    }


    query = "SELECT MAX(id) FROM person;";
    auto id = stoi(worker->execute(query)[0][0]);
    return get(id);
}

int PersonManager::remove(const Person *model) const {
    if (!model->pk) {
        return 0;
    }
    DBWorker* worker = DBWorker::getInstance();
    string query = (boost::format("DELETE FROM person WHERE id=%s;") % to_string(model->pk)).str();
    worker->execute(query)[0];
    return 0;
}
