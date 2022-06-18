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
    static int getDaysOfMonth(int year, int month);
    static bool IsLeapYear(int year);
    static Date* now();

    friend stringstream& operator<<(stringstream& stream, const Date& date);

    void operator +=(const Date& date);
    void operator -=(const Date& date);
private:
    static bool IsInvalidDate(int year, int month, int day);
    void ToCorrect();
    int month;
    int year;
    int day;
};

