//
// Created by dgalytskyi on 6/12/24.
//

#ifndef CPP_CAR_H
#define CPP_CAR_H

#include <iostream>
#include "../Utilities/strdup_new.h"

using namespace std;

namespace CPP {

    class Car {
    private:
        const char *model;
        int year;
        double price;
    public:
        Car();

        Car(const char *model, int year, double price);

        Car(const Car &other);

        Car &operator=(const Car &other);

        ~Car();

        [[nodiscard]] const char *getModel() const;

        void setModel(const char *model);

        [[nodiscard]] int getYear() const;

        void setYear(int year);

        [[nodiscard]] double getPrice() const;

        void setPrice(double price);

        void operator+=(int value);

        void operator-=(int value);

        void operator++();

        void operator--();

        double operator-(const Car &other) const;

        double operator+(const Car &other) const;
    };

    ostream &operator<<(ostream &os, Car &car);
    istream &operator>>(istream &is, Car &car);

} // CPP

#endif //CPP_CAR_H
