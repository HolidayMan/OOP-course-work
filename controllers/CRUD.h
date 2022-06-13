#pragma once
#include "../views/View.h"


template<class T>
class CRUD {
    virtual View<T>* getView() = 0;
    virtual T* create() = 0;
    virtual T* read() = 0;
    virtual T* update() = 0;
    virtual T* remove() = 0;
};
