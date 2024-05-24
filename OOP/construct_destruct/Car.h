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
        Car() {
            this->model = new char[]{"toyota"};
            this->country = new char[]{"japan"};
            this->color = new char[]{"gray"};
            this->year = 2009;
            this->price = 50234.12;
        }

        Car(const char *model, const char *country, const char *color, int year, double price) {
            this->model = model;
            this->country = country;
            this->color = color;
            this->year = year;
            this->price = price;
        }

        void init(char *model, char *country, char *color, int year, double price) {
            this->model = model;
            this->country = country;
            this->color = color;
            this->year = year;
            this->price = price;
        }

        void input() {
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

        void print() const {
            cout << "Model: " << this->model << endl
                 << "Country: " << this->country << endl
                 << "Color: " << this->color << endl
                 << "Year: " << this->year << endl
                 << "Price: " << this->price << endl
                 << endl;
        }

        ~Car() {
            delete[] this->model;
            delete[] this->country;
            delete[] this->color;
        }
    };
}

#endif //CPP_CAR_H
