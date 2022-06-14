#include <iostream>
#include <vector>
#include "PersonInQueue.h"
#include "PersonInQueueManager.h"
#include "../DBWorker.h"
#include "Dwelling.h"
#include "Person.h"
#include "fields/Date.h"
#include <boost/format.hpp>
#include <cstring>
#include <sstream>
#include "../Exceptions.h"
#include "Filter.h"

using namespace std;

PersonInQueue* initPersonInQueueWithPk(int pk, Date* _dateAdded, Person* _person, bool _isSatisfied, Dwelling* _dwelling=nullptr) {
    auto* personInQueue = new PersonInQueue(_dateAdded, _person, _isSatisfied, _dwelling);
    personInQueue->pk = pk;
    return personInQueue;
}

vector<PersonInQueue*> PersonInQueueManager::getList() const {
    string query = "SELECT pq.person_id as 'id', pq.added_date, pq.dwelling as dwelling_id, pq.is_satisfied, "
                   "p.name, p.birth_date, p.sex, p.family, d.address, d.rooms "
                   "FROM person_in_queue pq "
                   "INNER JOIN person p ON p.id = pq.person_id "
                   "LEFT JOIN dwelling d ON d.id = pq.dwelling;";

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(query);
    vector<PersonInQueue*> peopleInQueue;
    for (auto row: result) {
        int id = stoi(row[0]);
        Dwelling* dwelling = strcmp(row[2].c_str(), "NULL") != 0 ? initDwellingWithPk(stoi(row[2]), row[8], stoi(row[9])) : nullptr;
        Person* person = initPersonWithPk(id, row[4], new Date(row[5]), row[6], row[7]);
        peopleInQueue.push_back(initPersonInQueueWithPk(id, new Date(row[1]), person, stoi(row[3]), dwelling));
    }
    return peopleInQueue;

}

PersonInQueue* PersonInQueueManager::get(int pk) const {
    string query = "SELECT pq.person_id as 'id', pq.added_date, pq.dwelling as dwelling_id, pq.is_satisfied, "
                   "p.name, p.birth_date, p.sex, p.family, d.address, d.rooms "
                   "FROM person_in_queue pq "
                   "INNER JOIN person p ON p.id = pq.person_id "
                   "LEFT JOIN dwelling d ON d.id = pq.dwelling "
                   "WHERE pq.person_id = %d";
    query = (boost::format(query) % pk).str();
    DBWorker* worker = DBWorker::getInstance();
    auto resultVector = worker->execute(query);
    if (resultVector.empty()) {
        throw Exception("Can not find PersonInQueue with pk=" + to_string(pk));
    }
    auto result = resultVector[0];

    int id = stoi(result[0]);
    Dwelling* dwelling = strcmp(result[2].c_str(), "NULL") != 0 ? initDwellingWithPk(stoi(result[2]), result[8], stoi(result[9])) : nullptr;
    Person* person = initPersonWithPk(id, result[4], new Date(result[5]), result[6], result[7]);
    return initPersonInQueueWithPk(id, new Date(result[1]), person, stoi(result[3]), dwelling);
}

vector<PersonInQueue *> PersonInQueueManager::filter(Filter* condition) const {
    std::stringstream ss;
    ss << "SELECT * FROM person_in_queue WHERE " << condition->getRepresentation("");

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(ss.str());
    vector<PersonInQueue*> peopleInQueue;
    for (auto row: result) {
        int id = stoi(row[0]);
        peopleInQueue.push_back(get(id));
    }

    return peopleInQueue;
}

PersonInQueue* PersonInQueueManager::save(const PersonInQueue* model) const {
    string query = "INSERT INTO person_in_queue (person_id, added_date, is_satisfied, dwelling) VALUES ('%d', '%s', '%d', '%d');";
    query = (boost::format(query) % model->person->pk % model->dateAdded->toRepresentation() % model->isSatisfied % model->dwelling->pk).str();
    bool create = true;
    if (model->pk != 0) {
        query = "UPDATE person_in_queue SET added_date='%s', is_satisfied='%d', dwelling='%d' WHERE person_id=%d;";
        query = (boost::format(query) % model->dateAdded->toRepresentation() % model->isSatisfied % model->dwelling->pk % model->pk).str();
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

int PersonInQueueManager::remove(const PersonInQueue *model) const {
    if (!model->pk) {
        return 0;
    }
    DBWorker* worker = DBWorker::getInstance();
    string query = "DELETE FROM person_in_queue WHERE person_id=" + to_string(model->pk) + ";";
    worker->execute(query);
    return 0;
}



