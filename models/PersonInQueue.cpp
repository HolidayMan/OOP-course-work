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
