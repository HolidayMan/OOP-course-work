#pragma once
#include <iostream>

using namespace std;

template<class T>
class View {
    virtual string getScreenData() = 0;
};