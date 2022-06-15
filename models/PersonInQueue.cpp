#include <iostream>
#include "fields/Date.h"
#include "PersonInQueue.h"
#include "PersonInQueueManager.h"

using namespace std;


PersonInQueue::PersonInQueue(Date* _dateAdded, Person* _person, bool _isSatisfied, Dwelling* _dwelling)
: dateAdded(_dateAdded), person(_person), isSatisfied(_isSatisfied), dwelling(_dwelling), manager(new PersonInQueueManager()) {}

PersonInQueue *PersonInQueue::save() const {
    return manager->save(this);
}

int PersonInQueue::remove() const {
    return manager->remove(this);
}

PersonInQueue& PersonInQueue::operator=(const PersonInQueue& personInQueue) {
    person = personInQueue.person;
    dateAdded = personInQueue.dateAdded;
    manager = personInQueue.manager;
    pk = personInQueue.pk;
    dwelling = personInQueue.dwelling;

    return *this;
}


PersonInQueue::PersonInQueue() = default;
