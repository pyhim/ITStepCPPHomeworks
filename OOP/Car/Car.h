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
        string model;
        string color;
        string country;
        int year;
        double price;
    public:
        Car();

        Car(string model, string color, string country, int year, double price);

        Car(const Car &other);

        Car &operator=(const Car &other);

        [[nodiscard]] basic_string<char> getModel() const;

        void setModel(const string &model);

        [[nodiscard]] int getYear() const;

        void setYear(int year);

        [[nodiscard]] double getPrice() const;

        void setPrice(double price);

        [[nodiscard]] const string &getColor() const;

        void setColor(const string &color);

        [[nodiscard]] const string &getCountry() const;

        void setCountry(const string &country);

        void operator+=(int value);

        void operator-=(int value);

        void operator++();

        void operator--();

        double operator-(const Car &other) const;

        double operator+(const Car &other) const;

        Car(Car &&other) noexcept;

        Car &operator=(Car &&other) noexcept;
    };

    ostream &operator<<(ostream &os, Car &car);
    istream &operator>>(istream &is, Car &car);

} // CPP

#endif //CPP_CAR_H
