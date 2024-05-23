//
// Created by dgalytskyi on 5/23/24.
//

#ifndef CPP_CAR_H
#define CPP_CAR_H

#include <iostream>
#include <ios>
#include <limits>
#include <cstring>

using namespace std;

namespace CPP {
    class Car {
    private:
        char *model;
        char *country;
        char *color;
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

        Car(char *model, char *country, char *color, int year, double price) {
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

            cout << "Enter the model: ";
            cin.getline(buffer, SIZE);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            this->model = new char[strlen(buffer)];
            strcpy(this->model, buffer);

            cout << "Enter the country: ";
            cin.getline(buffer, SIZE);
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            this->country = new char[strlen(buffer)];
            strcpy(this->country, buffer);

            cout << "Enter the color: ";
            cin.getline(buffer, SIZE);
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            this->color = new char[strlen(buffer)];
            strcpy(this->color, buffer);

            cout << "Enter the year: ";
            cin >> this->year;
            cout << "Enter the price: ";
            cin >> this->price;
        }

        void print() const {
            cout << "Model: " << this->model
                 << "Country: " << this->country
                 << "Color: " << this->color
                 << "Year: " << this->year
                 << "Price: " << this->price;
        }

        ~Car() {
            delete[] this->model;
            delete[] this->country;
            delete[] this->color;
        }
    };
}

#endif //CPP_CAR_H
