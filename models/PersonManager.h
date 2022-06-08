#pragma once
#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Person.h"

using namespace std;

class Person;

class PersonManager: public ModelManager<Person> {
public:
    vector<Person*> getList() const override;
    Person* get() const override;
    vector<Person*> filter() const override;
    Person* save(const Person* model) const override;
};
