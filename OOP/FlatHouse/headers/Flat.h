//
// Created by dgalytskyi on 5/30/24.
//

#ifndef CPP_FLAT_H
#define CPP_FLAT_H

#include <cstdio>
#include "Person.h"

namespace CPP {

    class Flat {
    private:
        size_t family_size;
        double quadrature;
        Person *family;
    public:
        Flat();

        Flat(Person *family, size_t family_size);

        explicit Flat(double quadrature);

        Flat(Person *family, size_t family_size, double quadrature);

        Flat(const Flat &from);

        [[nodiscard]] Person *getFamily() const;

        void setFamily(Person *family, size_t family_size);

        [[nodiscard]] double getQuadrature() const;

        void setQuadrature(double quadrature);

        void addFamilyMember(const Person& person);

        Flat& operator=(const Flat& other);

        ~Flat();
    };

} // CPP

#endif //CPP_FLAT_H
