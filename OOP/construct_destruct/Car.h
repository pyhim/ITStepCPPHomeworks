//
// Created by dgalytskyi on 5/23/24.
//

#ifndef CPP_CAR_H
#define CPP_CAR_H

#include <iostream>
#include <cstring>

using namespace std;

namespace CPP {
    class Car {
    private:
        const char *model;
        const char *country;
        const char *color;
        int year;
        double price;
    public:
        Car();

        Car(const char *model, const char *country, const char *color, int year, double price);

        void init(char *model, char *country, char *color, int year, double price);

        void input();

        void print() const;

        Car(const Car &object);

        ~Car();
    };
}

#endif //CPP_CAR_H
