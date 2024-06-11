//
// Created by dgalytskyi on 6/10/24.
//

#include <cstring>
#include <iostream>
#include "MyString.h"
#include "../Utilities/strdup_new.h"

// For clarifying magic numbers
#define INIT_LENGTH 80
#define NOT_FOUND (-1)

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

        delete[] this->string;

        this->string = strdup(string_buffer);
        this->length = (long) strlen(string_buffer);
    }

    void MyString::output() const {
        cout << this->string;
    }

    const char *MyString::getString() const {
        return this->string;
    }

    long MyString::getLength() const {
        return this->length;
    }

    void MyString::myStrcpy(const MyString &other) {
        delete[] this->string;

        this->string = strdup(other.string);
    }

    bool MyString::myStrstr(const char *string) const {
        return strstr(this->string, string) != nullptr;
    }

    long MyString::myChr(char c) const {
        for (long i = 0; i < this->length; i++) {
            char cursor = this->string[i];

            if (cursor == c) {
                return i;
            }
        }

        return NOT_FOUND;
    }

    long MyString::myStrlen() const {
        return this->length;
    }

    void MyString::myConcat(const MyString &other) {
        const long SIZE = this->length + other.length + 1;
        char *new_string = new char[SIZE];

        strcpy(new_string, this->string);
        strcat(new_string, other.string);

        delete[] this->string;

        this->string = new_string;
        this->length = SIZE - 1;
    }

    void MyString::myDelChr(char c) {
        long index = MyString::myChr(c);

        if (index == NOT_FOUND) {
            return;
        }

        const long NEW_LENGTH = this->length - 1;
        char *new_string = new char[NEW_LENGTH + 1];

        for (long i = 0, j = 0; i < this->length; i++) {
            if (i != index) {
                new_string[j++] = this->string[i];
            }
        }
        new_string[NEW_LENGTH] = '\0';

        delete[] this->string;

        this->string = new_string;
        this->length = NEW_LENGTH;
    }

    int MyString::myStrCmp(const MyString &other) const {
        if (this->length < other.length) {
            return -1;
        } else if (this->length > other.length) {
            return 1;
        } else {
            return 0;
        }
    }

    MyString MyString::operator+(MyString &other) const {
        char *new_string = strdup(this->string);
        strcat(new_string, other.string);

        MyString result = MyString(new_string);

        return result;
    }

    void MyString::operator+=(MyString &other) {
        this->myConcat(other);
    }

    void MyString::operator+=(const char *string) {
        MyString to_concat(string);

        this->myConcat(to_concat);
    }

    void MyString::operator-=(char c) {
        this->myDelChr(c);
    }

    void MyString::operator*(int value) {
        for (long i = 1; i < value; i++) {
            *this += *this;
        }
    }

    char MyString::operator[](long index) {
        return this->string[index];
    }

    int MyString::getInstances() {
        return MyString::instances;
    }
} // CPP