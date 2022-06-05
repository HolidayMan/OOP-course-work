
#ifndef OOP_COURSE_WORK_MODELMANAGER_H
#define OOP_COURSE_WORK_MODELMANAGER_H

#include "Model.h"
#include <istream>

using namespace std;

template<class T>
class ModelManager {
public:
    virtual vector<T*> get_list() = 0;
    virtual T* get() = 0;
    virtual vector<T*> filter() = 0;
    virtual T* save(T* model) = 0;
};

#endif //OOP_COURSE_WORK_MODELMANAGER_H
