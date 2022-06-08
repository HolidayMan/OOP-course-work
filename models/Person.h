#pragma once

#include "Model.h"
#include "PersonManager.h"
#include "fields/Date.h"


class PersonManager;

class Person: public Model {
public:
    Person(string _name, Date* _birthDate, string _sex, string family);
    const string tableName = "person";
    string name;
    const PersonManager* manager;
    Date* birthDate;
    string sex;
    string family;
};

