#pragma once
#include <istream>
#include <vector>
#include "Filter.h"

using namespace std;

template<class T>
class ModelManager {
public:
    virtual vector<T*> getList() const = 0;
    virtual T* get(int pk) const = 0;
    virtual vector<T*> filter(Filter* condition) const = 0;
    virtual T* save(const T* model) const = 0;
    virtual int remove(const T* model) const = 0;
};
