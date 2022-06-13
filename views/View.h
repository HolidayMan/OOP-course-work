#pragma once
#include <iostream>
#include <utility>

using namespace std;

class View {
public:
    explicit View(string _header) : header(std::move(_header)) {}
    virtual string getScreenData() = 0;

protected:
    string header;
};