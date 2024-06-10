//
// Created by dgalytskyi on 6/10/24.
//

#include <cstring>
#include <iostream>
#include "MyString.h"
#include "../Utilities/strdup_new.h"

#define INIT_LENGTH 80

using namespace std;

namespace CPP {
    int MyString::instances = 0;

    MyString::MyString() : length(INIT_LENGTH), string(new char[INIT_LENGTH]) {
        MyString::instances++;
    }

    MyString::MyString(long length) : length(length), string(new char[length]) {
        MyString::instances++;
    }

    MyString::MyString(const char *string) : string(strdup(string)), length((long) strlen(string)) {
        MyString::instances++;
    }

    MyString::~MyString() {
        MyString::instances--;

        delete[] this->string;
    }

    MyString::MyString(const MyString &other) : MyString(other.string) {

    }

    MyString &MyString::operator=(const MyString &other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->string;

        this->string = strdup(other.string);
        this->length = other.length;

        return *this;
    }

    void MyString::input() {
        const unsigned short SIZE = 100;
        char string_buffer[SIZE];

        cout << "Enter your string: ";
        cin.getline(string_buffer, SIZE);
        this->string = strdup(string_buffer);
        this->length = (long) strlen(string_buffer);
    }

    void MyString::output() const {
        cout << this->string;
    }
} // CPP