#include <iostream>
#include <vector>
#include "ModelManager.h"
#include "Date.cpp"

using namespace std;


class DateManager: public ModelManager<Date> {
public:
    vector<Date*> get_list() override {

    }
    Date* get() {

    }
    vector<Date*> filter() {

    }
    Date* save(Date* model) {

    }
};

