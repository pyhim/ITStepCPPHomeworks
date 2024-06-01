//
// Created by dgalytskyi on 5/27/24.
//

#ifndef CPP_PERSON_H
#define CPP_PERSON_H

#include "Date.h"
#include <iostream>

using std::cout;
using std::endl;

namespace CPP {

    class Person {
    private:
        const char *ID;
        const char *firstname;
        const char *surname;
        const char *lastname;
        Date date_of_birth;
    public:
        Person();

        Person(const char *ID, const char *firstname, const char *surname, const char *lastname, Date date_of_birth);

        Person(const char *ID, const char *firstname, const char *surname, Date date_of_birth);

        Person(const Person &from);

        [[nodiscard]] const char *getId() const;

        void setId(const char *id);

        [[nodiscard]] const char *getFirstname() const;

        void setFirstname(const char *firstname);

        [[nodiscard]] const char *getSurname() const;

        void setSurname(const char *surname);

        [[nodiscard]] const char *getLastname() const;

        void setLastname(const char *lastname);

        [[nodiscard]] const Date &getDateOfBirth() const;

        void setDateOfBirth(const Date &dateOfBirth);

        void print_credentials() const;

        Person& operator=(const Person &other);

        ~Person();
    };

} // CPP

#endif //CPP_PERSON_H
