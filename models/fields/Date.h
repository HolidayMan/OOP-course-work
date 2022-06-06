#pragma once
#include <iostream>
#include "Field.h"

using namespace std;

class Date: public Field<string> {
public:
    Date(int _year, int _month, int _day);
    explicit Date(const string& isoDate);

    string toRepresentation() override;
private:
    int month;
    int year;
    int day;
};

