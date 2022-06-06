#pragma once
#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Person.h"

using namespace std;

class Person;

class PersonManager: public ModelManager<Person> {
public:
    vector<Person*> getList() override;
    Person* get() override;
    vector<Person*> filter() override;
    Person* save(Person* model) override;
};
