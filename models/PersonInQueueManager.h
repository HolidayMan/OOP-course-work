#pragma once

#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "PersonInQueue.h"
#include "Filter.h"
#include "fields/Date.h"
#include "Person.h"
#include "Dwelling.h"

using namespace std;


class PersonInQueue;

class PersonInQueueManager: public ModelManager<PersonInQueue> {
public:
    vector<PersonInQueue*> getList() const override;
    PersonInQueue* get(int pk) const override;
    vector<PersonInQueue*> filter(Filter* condition) const override;
    PersonInQueue* save(const PersonInQueue* model) const override;
    int remove(const PersonInQueue* model) const override;
};

PersonInQueue* initPersonInQueueWithPk(int pk, Date* _dateAdded, Person* _person, bool _isSatisfied, Dwelling* _dwelling);