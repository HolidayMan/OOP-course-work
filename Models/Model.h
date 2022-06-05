
#ifndef OOP_COURSE_WORK_MODEL_H
#define OOP_COURSE_WORK_MODEL_H

#include <istream>
#include "ModelManager.h"


using namespace std;

class Model {
public:
    const int pk;
    string tableName;
    ModelManager* manager;
    virtual void save(Model* model) = 0;
};


#endif //OOP_COURSE_WORK_MODEL_H
