//
// Created by dgalytskyi on 5/27/24.
//

#include <iostream>
#include "headers/Date.h"

using namespace std;

namespace CPP {

    Date::Date(int day, int month, int year) {
        if (day > 31 || day < 0 || month > 12 || month < 0 || year > 9999 || year < 0) {
            cerr << "Wrong date format";
            return;
        }

        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date::Date() : day(1), month(1), year(1970) {}

    void Date::setDay(int day) {
        Date::day = day;
    }

    void Date::setMonth(int month) {
        Date::month = month;
    }

    void Date::setYear(int year) {
        Date::year = year;
    }

    int Date::getDay() const {
        return day;
    }

    int Date::getMonth() const {
        return month;
    }

    int Date::getYear() const {
        return year;
    }

} // CPP