#pragma once

#include <iostream>
#include "Model.h"
#include "PersonInQueueManager.h"
#include "fields/Date.h"
#include "Person.h"
#include "Dwelling.h"

class PersonInQueueManager;
class PersonInQueue: public Model {
public:
    PersonInQueue(Date* _dateAdded, Person* _person, bool _isSatisfied, Dwelling* _dwelling=nullptr);
    PersonInQueue();
    const string tableName = "person_in_queue";
    const PersonInQueueManager* manager{};
    Date* dateAdded{};
    Person* person{};
    bool isSatisfied{};
    Dwelling* dwelling{};
    PersonInQueue* save() const override;
    int remove() const override;

    PersonInQueue& operator=(const PersonInQueue& personInQueue);
};
