#include <cstring>
#include "QueueDwelling.h"
#include "../DBWorker.h"

QueueDwelling::QueueDwelling() {
    string query = "SELECT pq.person_id as 'id', pq.added_date, pq.dwelling as dwelling_id, pq.is_satisfied, "
                   "p.name, p.birth_date, p.sex, p.family, d.address, d.rooms "
                   "FROM person_in_queue pq "
                   "INNER JOIN person p ON p.id = pq.person_id "
                   "LEFT JOIN dwelling d ON d.id = pq.dwelling "
                   "ORDER BY pq.added_date; ";

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(query);

    size = result.size();
    persons = new PersonInQueue[size];

    int i = 0;
    for (auto row: result) {
        int id = stoi(row[0]);
        Dwelling* dwelling = strcmp(row[2].c_str(), "NULL") != 0 ? initDwellingWithPk(stoi(row[2]), row[8], stoi(row[9])) : nullptr;
        Person* person = initPersonWithPk(id, row[4], new Date(row[5]), row[6], row[7]);

        persons[i] = *initPersonInQueueWithPk(id, new Date(row[1]), person, stoi(row[3]), dwelling);
        i++;
    }
}

size_t QueueDwelling::Size() const {
    return size;
}

PersonInQueue *QueueDwelling::begin() {
    return persons;
}

PersonInQueue *QueueDwelling::end() {
    return persons + size;
}
