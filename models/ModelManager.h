#pragma once
#include <istream>

using namespace std;

template<class T>
class ModelManager {
public:
    virtual vector<T*> getList() = 0;
    virtual T* get() = 0;
    virtual vector<T*> filter() = 0;
    virtual T* save(T* model) = 0;
};
