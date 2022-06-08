#pragma once

#include <istream>
#include "ModelManager.h"


using namespace std;

class Model {
public:
    int pk;
    const string tableName;
    const ModelManager<Model>* manager;
    Model* save() const {
        return manager->save(this);
    }
};
