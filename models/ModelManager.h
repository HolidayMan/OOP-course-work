#pragma once
#include <istream>

using namespace std;

template<class T>
class ModelManager {
public:
    virtual vector<T*> getList() const = 0;
    virtual T* get(int pk) const = 0;
    virtual vector<T*> filter() const = 0;
    virtual T* save(const T* model) const = 0;
    virtual int remove(const T* model) const = 0;
};
