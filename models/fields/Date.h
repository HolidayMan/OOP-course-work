#pragma once
#include <iostream>
#include <sstream>
#include "Field.h"

using namespace std;

class Date: public Field<string> {
public:
    Date(int _year, int _month, int _day);
    explicit Date(const string& isoDate);

    string toRepresentation() override;
    string toString() const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setDate(int y, int m, int d);

    friend stringstream& operator<<(stringstream& stream, const Date& date);

    void operator +=(const Date& date);
    void operator -=(const Date& date);
private:
    bool IsInvalidDate(int year, int month, int day);
    bool IsLeapYear(int year);
    int YearsOfMonth(int year, int month);
    void ToCorrect();
    int month;
    int year;
    int day;
};

