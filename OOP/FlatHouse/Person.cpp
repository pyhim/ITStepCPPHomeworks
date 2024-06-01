//
// Created by dgalytskyi on 5/27/24.
//

#include <cstring>
#include "headers/Person.h"

namespace CPP {
    // Я реализовал свой вариант способа дупликации строки, потому что стандартная функция выделяет память
    // через malloc(), и удаление дуплицированных строк через delete[] ведёт к необозначенному поведению,
    // возможно вызывая ошибки и повреждение в памяти. Реализация этой функции через new[] исключает возможность
    // таких ошибок.
    char* strdup(const char* str) {
        if (str == nullptr) {
            return nullptr;
        }
        size_t len = std::strlen(str) + 1;
        char* copy = new char[len];
        std::memcpy(copy, str, len);
        return copy;
    }

    Person::Person() : Person(
            "unknown",
            "unknown",
            "unknown",
            "unknown",
            Date()
    ) {}

    Person::Person(
            const char *ID,
            const char *firstname,
            const char *surname,
            CPP::Date date_of_birth
    ) : ID(strdup(ID)), firstname(strdup(firstname)), surname(strdup(surname)), date_of_birth(date_of_birth),
        lastname(nullptr) {
    }

    Person::Person(
            const char *ID,
            const char *firstname,
            const char *surname,
            const char *lastname,
            CPP::Date date_of_birth
    ) : Person(ID, firstname, surname, date_of_birth) {
        this->lastname = strdup(lastname);
    }

    Person::Person(const Person &from)
            : Person(
            from.ID,
            from.firstname,
            from.surname,
            from.lastname,
            from.date_of_birth
    ) {}

    Person::~Person() {
        delete[] this->ID;
        delete[] this->firstname;
        delete[] this->surname;
        delete[] this->lastname;
    }

    const char *Person::getId() const {
        return ID;
    }

    void Person::setId(const char *id) {
        delete[] this->ID;
        Person::ID = id;
    }

    const char *Person::getFirstname() const {
        return firstname;
    }

    void Person::setFirstname(const char *firstname) {
        delete[] this->firstname;
        Person::firstname = firstname;
    }

    const char *Person::getSurname() const {
        return surname;
    }

    void Person::setSurname(const char *surname) {
        delete[] this->surname;
        Person::surname = surname;
    }

    const char *Person::getLastname() const {
        return lastname;
    }

    void Person::setLastname(const char *lastname) {
        delete[] lastname;
        Person::lastname = lastname;
    }

    const Date &Person::getDateOfBirth() const {
        return date_of_birth;
    }

    void Person::setDateOfBirth(const Date &dateOfBirth) {
        date_of_birth = dateOfBirth;
    }

    Person& Person::operator=(const Person &other) {
        if (this == &other) {
            return *this; // handle self-assignment
        }

        // Release existing resources
        delete[] ID;
        delete[] firstname;
        delete[] surname;
        delete[] lastname;

        // Allocate new memory and copy data
        ID = strdup(other.ID);
        firstname = strdup(other.firstname);
        surname = strdup(other.surname);
        lastname = other.lastname ? strdup(other.lastname) : nullptr;
        date_of_birth = other.date_of_birth;

        return *this;
    }

    void Person::print_credentials() const {
        Date dof = getDateOfBirth();
        int day = dof.getDay();
        int month = dof.getMonth();
        int year = dof.getYear();

        cout << getFirstname() << endl
             << getSurname() << endl
             << getLastname() << endl
             << getId() << endl
             << day << '.' << month << '.' << year << endl;
    }

} // CPP