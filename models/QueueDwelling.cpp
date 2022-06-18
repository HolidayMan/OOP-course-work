#include <cstring>
#include "QueueDwelling.h"
#include "../DBWorker.h"

QueueDwelling::QueueDwelling() {
    string query = "SELECT pq.person_id as 'id', pq.added_date, pq.dwelling as dwelling_id, pq.is_satisfied, "
                   "p.name, p.birth_date, p.sex, p.family, d.address, d.rooms "
                   "FROM person_in_queue pq "
                   "INNER JOIN person p ON p.id = pq.person_id "
                   "LEFT JOIN dwelling d ON d.id = pq.dwelling "
                   "WHERE pq.is_satisfied = 0 "
                   "ORDER BY pq.added_date; ";

    DBWorker* worker = DBWorker::getInstance();
    auto result = worker->execute(query);

    _size = result.size();
    queue = new PersonInQueue[_size];

    int i = 0;
    for (auto row: result) {
        int id = stoi(row[0]);
        Dwelling* dwelling = strcmp(row[2].c_str(), "NULL") != 0 ? initDwellingWithPk(stoi(row[2]), row[8], stoi(row[9])) : nullptr;
        Person* person = initPersonWithPk(id, row[4], new Date(row[5]), row[6], row[7]);

        queue[i] = *initPersonInQueueWithPk(id, new Date(row[1]), person, stoi(row[3]), dwelling);
        i++;
    }
}

size_t QueueDwelling::size() const {
    return _size;
}

PersonInQueue *QueueDwelling::begin() {
    return queue;
}

PersonInQueue *QueueDwelling::end() {
    return queue + _size;
}

QueueDwelling::~QueueDwelling() {
    for (int i = 0; i < _size; i++) {
        delete queue[i].person;
        delete queue[i].dwelling;
    }
    delete[] queue;

}

PersonInQueue *QueueDwelling::operator[](size_t index) {
    return &queue[index];
}

bool QueueDwelling::empty() const {
    return _size == 0;
}

QueueDwelling::QueueDwelling(vector<PersonInQueue *> _queue) {
    _size = _queue.size();
    queue = new PersonInQueue[_size];
    for (int i = 0; i < _size; i++) {
        queue[i] = *_queue[i];
    }
}
