#pragma once

#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "PersonInQueue.h"

using namespace std;


class PersonInQueue;

class PersonInQueueManager: public ModelManager<PersonInQueue> {
public:
    vector<PersonInQueue*> getList() const override;
    PersonInQueue* get() const override;
    vector<PersonInQueue*> filter() const override;
    PersonInQueue* save(const PersonInQueue* model) const override;
};

