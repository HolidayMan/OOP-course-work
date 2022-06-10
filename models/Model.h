#pragma once

#include <istream>
#include "ModelManager.h"


using namespace std;

class Model {
public:
    int pk;
    const string tableName;
    const ModelManager<Model>* manager;
    virtual Model* save() const = 0;
    virtual int remove() const = 0;
};
