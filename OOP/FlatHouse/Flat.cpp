//
// Created by dgalytskyi on 5/30/24.
//

#include "headers/Flat.h"

namespace CPP {
    Flat::Flat() : family(nullptr), family_size(0), quadrature(0) {}

    Flat::Flat(double quadrature) : family(nullptr), family_size(0), quadrature(quadrature) {}

    Flat::Flat(Person *family, size_t family_size) : family(new Person[family_size]), family_size(family_size) {
        for (size_t i = 0; i < family_size; i++) {
            this->family[i] = family[i];
        }

        this->quadrature = 0;
    }

    Flat::Flat(Person *family, size_t family_size, double quadrature) : Flat(family, family_size) {
        this->quadrature = quadrature;
    }

    Person *Flat::getFamily() const {
        return family;
    }

    Flat::Flat(const Flat &from) : Flat(from.family, from.family_size, from.quadrature) {}

    void Flat::setFamily(Person *family, size_t family_size) {
        delete[] this->family;

        this->family = new Person[family_size];
        for (size_t i = 0; i < family_size; i++) {
            this->family[i] = family[i];
        }
    }

    double Flat::getQuadrature() const {
        return quadrature;
    }

    void Flat::setQuadrature(double quadrature) {
        Flat::quadrature = quadrature;
    }

    Flat::~Flat() {
        delete[] family;
    }

    void Flat::addFamilyMember(const Person& person) {
        Person *old_family = this->family;

        this->family_size++;
        this->family = new Person[family_size];

        size_t i = 0;
        for (; i < family_size - 1; i++) {
            this->family[i] = family[i];
        }
        this->family[i] = person;

        delete[] old_family;
    }
} // CPP