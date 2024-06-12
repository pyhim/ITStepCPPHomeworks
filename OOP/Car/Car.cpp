//
// Created by dgalytskyi on 6/12/24.
//

#include "Car.h"

using namespace std;

namespace CPP {
    Car::Car() : model(nullptr), year(0), price(0.0) {

    }

    Car::Car(const char *model, int year, double price) : model(strdup(model)), year(year), price(price) {

    }

    Car::Car(const Car &other) : Car(other.model, other.year, other.price) {

    }

    Car &Car::operator=(const Car &other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->model;

        this->model = strdup(other.model);
        this->year = other.year;
        this->price = other.price;

        return *this;
    }

    Car::~Car() {
        delete[] this->model;
    }

    const char *Car::getModel() const {
        return model;
    }

    void Car::setModel(const char *model) {
        delete[] this->model;

        this->model = strdup(model);
    }

    int Car::getYear() const {
        return year;
    }

    void Car::setYear(int year) {
        this->year = year;
    }

    double Car::getPrice() const {
        return price;
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

    ostream &operator<<(ostream &os, Car &car) {
        os << car.getModel() << ' ' << car.getYear() << ' ' << car.getPrice() << endl;
        return os;
    }

    istream &operator>>(istream &is, Car &car) {
        char model[100];
        int year;
        double price;

        cout << "Enter year: ";
        is >> year;
        cout << "Enter price: ";
        is >> price;
        is.ignore();
        cout << "Enter model: ";
        is.getline(model, 100);

        car.setModel(model);
        car.setPrice(price);
        car.setYear(year);

        return is;
    }
}