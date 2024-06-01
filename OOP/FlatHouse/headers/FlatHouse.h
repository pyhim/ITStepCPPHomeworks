//
// Created by dgalytskyi on 5/31/24.
//

#ifndef CPP_FLATHOUSE_H
#define CPP_FLATHOUSE_H

#include <cstdio>
#include "Flat.h"

namespace CPP {

    class FlatHouse {
    private:
        size_t number_of_flats;
        Flat *flats;
    public:
        FlatHouse(Flat *flats, size_t number_of_flats);

        FlatHouse(const FlatHouse& from);

        [[nodiscard]] size_t getNumberOfFlats() const;

        [[nodiscard]] Flat *getFlats() const;

        [[nodiscard]] Flat getFlat(size_t index);

        ~FlatHouse();
    };

} // CPP

#endif //CPP_FLATHOUSE_H
