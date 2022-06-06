#pragma once

#include <istream>
#include "ModelManager.h"


using namespace std;

class Model {
public:
    int pk;
    const string tableName;
    ModelManager<Model>* manager;
    Model* save(Model* model) {
        return manager->save(this);
    }
};
