#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {}

Date::Date(const string& isoDate) {
    int y, m, d;
    sscanf(isoDate.c_str(), "%d-%d-%d", &y, &m, &d);
    month = m;
    year = y;
    day = d;
}

string Date::toRepresentation() {
    string y = to_string(year);
    string m = to_string(month);
    if (month < 10)
        m = "0" + to_string(month);
    string d = to_string(day);
    if (day < 10)
        d = "0" + to_string(day);
    return y + "-" + m + "-" + d;
}


