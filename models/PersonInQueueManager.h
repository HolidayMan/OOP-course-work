#pragma once

#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "PersonInQueue.h"

using namespace std;


class PersonInQueue;

class PersonInQueueManager: public ModelManager<PersonInQueue> {
public:
    vector<PersonInQueue*> getList() override;
    PersonInQueue* get() override;
    vector<PersonInQueue*> filter() override;
    PersonInQueue* save(PersonInQueue* model)  override;
};

