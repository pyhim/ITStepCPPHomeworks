//
// Created by dgalytskyi on 6/12/24.
//

#include "Car.h"

#include <utility>

using namespace std;

namespace CPP {
    Car::Car() : year(0), price(0.0) {

    }

    Car::Car(string model, string color, string country, int year, double price)
    : model(std::move(model)), color(std::move(color)), country(std::move(country)), year(year), price(price) {

    }

    Car::Car(const Car &other) = default;

    Car &Car::operator=(const Car &other) = default;

    basic_string<char> Car::getModel() const {
        return this->model;
    }

    void Car::setModel(const string &model) {
        this->model = model;
    }

    int Car::getYear() const {
        return this->year;
    }

    void Car::setYear(int year) {
        this->year = year;
    }

    double Car::getPrice() const {
        return this->price;
    }

    void Car::setPrice(double price) {
        this->price = price;
    }

    void Car::operator+=(int value) {
        this->price += value;
    }

    void Car::operator-=(int value) {
        this->price -= value;
    }

    void Car::operator++() {
        this->year++;
    }

    void Car::operator--() {
        this->year--;
    }

    double Car::operator-(const Car &other) const {
        return this->price - other.price;
    }

    double Car::operator+(const Car &other) const {
        return this->price + other.price;
    }

    Car::Car(Car &&other) noexcept : Car(other.model, other.color, other.country, other.year, other.price) {
        other.price = 0;
        other.year = 0;
    }

    Car &Car::operator=(Car &&other) noexcept {
        if (this == &other) {
            return *this;
        }

        this->model = other.model;
        this->color = other.color;
        this->country = other.country;
        this->price = other.price;
        this->year = other.year;

        other.price = 0;
        other.year = 0;

        return *this;
    }

    const string &Car::getColor() const {
        return this->color;
    }

    void Car::setColor(const string &color) {
        Car::color = color;
    }

    const string &Car::getCountry() const {
        return this->country;
    }

    void Car::setCountry(const string &country) {
        Car::country = country;
    }

    ostream &operator<<(ostream &os, Car &car) {
        os << car.getModel() << ' '
           << car.getColor() << ' '
           << car.getCountry() << ' '
           << car.getYear() << ' '
           << car.getPrice() << ' '
           << endl;

        return os;
    }

    istream &operator>>(istream &is, Car &car) {
        string model, color, country;
        int year;
        double price;

        cout << "Enter year: ";
        is >> year;
        cout << "Enter price: ";
        is >> price;
        cout << "Enter model: ";
        is >> model;
        cout << "Enter color: ";
        is >> color;
        cout << "Enter country: ";
        is >> country;

        car.setModel(model);
        car.setColor(color);
        car.setCountry(country);
        car.setPrice(price);
        car.setYear(year);

        return is;
    }
}