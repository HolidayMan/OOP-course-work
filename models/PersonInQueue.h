#pragma once

#include <iostream>
#include "Model.h"
#include "PersonInQueueManager.h"
#include "fields/Date.h"
#include "Person.h"


class PersonInQueue: public Model {
public:
    const string tableName = "person_in_queue";
    PersonInQueueManager* manager;
    Date* date_added;
    Person* person;
    bool satisfied;
    // TODO: dwelling
};
