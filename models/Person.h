#pragma once

#include "Model.h"
#include "PersonManager.h"
//#include "fields/Date.h"

class PersonManager;

class Person: public Model {
    const string tableName = "person";
    PersonManager* manager;
    Date date_of_birth;
};

