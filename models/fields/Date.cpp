#include <iostream>
#include "Date.h"
#include "../../Exceptions.h"

using namespace std;

Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {
    if (IsInvalidDate(year, month, day)){
        throw Exception("Invalid date");
    }
}

Date::Date(const string& isoDate) {
    int y, m, d;
    sscanf(isoDate.c_str(), "%d-%d-%d", &y, &m, &d);

    if (IsInvalidDate(y, m, d)){
        throw Exception("Invalid date");
    }

    month = m;
    year = y;
    day = d;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::setDate(int y, int m, int d) {
    if (IsInvalidDate(y, m, d)) {
        throw Exception("Invalid date");
    }

    year = y;
    month = m;
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

void Date::operator+=(const Date& date) {
    year += date.year;
    month += date.month;
    day += date.day;

    if (IsInvalidDate(year, month, day)) {
        ToCorrect();
    }
}

void Date::operator-=(const Date &date) {
    if (year <= date.year) {
        throw Exception("Invalid date");
    }
    year -= date.year;

    if (month <= date.month) {
        month = 12 - date.month + month;
    } else {
        month -= date.month;
    }

    day -= date.day;


    if (IsInvalidDate(year, month, day)) {
        ToCorrect();
    }
}

stringstream &operator<<(stringstream &stream, const Date& date) {
    stream << date.day << "/" << date.month << "/" << date.year;
    return  stream;
}

bool Date::IsInvalidDate(int y, int m, int d) {
    if ((y < 1) ||
        (m < 1 || m > 12) ||
        (d < 1 || d > YearsOfMonth(y, m)))
    {
        return true;
    }
    return false;
}

int Date::YearsOfMonth(int y, int m) {
    int d;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    d = days[m - 1];
    if (m == 2 && IsLeapYear(y))
    {
        d += 1;
    }
    return d;

}

bool Date::IsLeapYear(int y) {
    if ((y % 400 == 0) ||
        ((y % 4 == 0) && (y % 100 != 0)) )
    {
        return true;
    }
    return false;
}

void Date::ToCorrect() {
    while (day > YearsOfMonth(year, month) || day <= 0)
    {
        if(day <= 0)
        {
            day += YearsOfMonth(year,(month - 1));
            if (month == 1)
            {
                month = 12;
                year--;
            }
            else
            {
                month--;
            }
        }
        else
        {
            day -= YearsOfMonth(year, month);
            if (month == 12)
            {
                year++;
                month = 1;
            }
            else
            {
                month++;
            }
        }
    }
}

int Date::getYear() const {
    return year;
}

string Date::toString() const {
    string y = to_string(year);
    string m = to_string(month);
    if (month < 10)
        m = "0" + to_string(month);
    string d = to_string(day);
    if (day < 10)
        d = "0" + to_string(day);
    return d + '.' + m + '.' + y;
}
