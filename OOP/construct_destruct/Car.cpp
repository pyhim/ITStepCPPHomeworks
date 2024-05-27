//
// Created by dgalytskyi on 5/27/24.
//

#include "Car.h"

using CPP::Car;

Car::Car() {
    this->model = new char[]{"toyota"};
    this->country = new char[]{"japan"};
    this->color = new char[]{"gray"};
    this->year = 2009;
    this->price = 50234.12;
}

Car::Car(const char *model, const char *country, const char *color, int year, double price) {
    this->model = model;
    this->country = country;
    this->color = color;
    this->year = year;
    this->price = price;
}

void Car::init(char *model, char *country, char *color, int year, double price) {
    this->model = model;
    this->country = country;
    this->color = color;
    this->year = year;
    this->price = price;
}

void Car::input() {
    const int SIZE = 25;
    char buffer[SIZE];
    char *to_insert;

    cout << "Enter the model: ";
    cin.getline(buffer, SIZE);
    to_insert = new char[strlen(buffer)];
    strcpy(to_insert, buffer);
    this->model = to_insert;

    cout << "Enter the country: ";
    cin.getline(buffer, SIZE);
    to_insert = new char[strlen(buffer)];
    strcpy(to_insert, buffer);
    this->country = to_insert;

    cout << "Enter the color: ";
    cin.getline(buffer, SIZE);
    to_insert = new char[strlen(buffer)];
    strcpy(to_insert, buffer);
    this->color = to_insert;

    cout << "Enter the year: ";
    cin >> this->year;
    cout << "Enter the price: ";
    cin >> this->price;
}

void Car::print() const {
    cout << "Model: " << this->model << endl
         << "Country: " << this->country << endl
         << "Color: " << this->color << endl
         << "Year: " << this->year << endl
         << "Price: " << this->price << endl
         << endl;
}

Car::Car(const Car &object) {
    char *to_insert;

    to_insert = new char[strlen(object.model) + 1];
    strcpy(to_insert, object.model);
    this->model = to_insert;

    to_insert = new char[strlen(object.country) + 1];
    strcpy(to_insert, object.country);
    this->country = to_insert;

    to_insert = new char[strlen(object.color) + 1];
    strcpy(to_insert, object.color);
    this->color = to_insert;

    this->year = object.year;
    this->price = object.price;
}

Car::~Car() {
    delete[] this->model;
    delete[] this->country;
    delete[] this->color;
}
