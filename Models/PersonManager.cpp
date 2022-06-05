
#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Person.cpp"

using namespace std;


class PersonManager: public ModelManager<Person> {
public:
    vector<Person*> get_list() override {

    }
    Person* get() {

    }
    vector<Person*> filter() {

    }
    Person* save(Person* model) {

    }
};
