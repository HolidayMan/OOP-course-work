#pragma once
#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Person.h"
#include "fields/Date.h"

using namespace std;

class Person;

class PersonManager: public ModelManager<Person> {
public:
    vector<Person*> getList() const override;
    Person* get(int pk) const override;
    vector<Person*> filter() const override;
    Person* save(const Person* model) const override;
    int remove(const Person* model) const override;
};

Person* initPersonWithPk(int pk, string _name, Date* _birthDate, string _sex, string _family);
