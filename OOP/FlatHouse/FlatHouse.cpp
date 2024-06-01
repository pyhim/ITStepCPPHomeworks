//
// Created by dgalytskyi on 5/31/24.
//

#include "headers/FlatHouse.h"

namespace CPP {
    FlatHouse::FlatHouse(Flat *flats, size_t number_of_flats) : flats(new Flat[number_of_flats]),
                                                                number_of_flats(number_of_flats) {
        for (size_t i = 0; i < number_of_flats; i++) {
            this->flats[i] = flats[i];
        }

    }

    FlatHouse::FlatHouse(const FlatHouse &from) : FlatHouse(from.flats, from.number_of_flats) {}


    size_t FlatHouse::getNumberOfFlats() const {
        return number_of_flats;
    }

    Flat *FlatHouse::getFlats() const {
        Flat *to_return = new Flat[this->number_of_flats];

        for (size_t i = 0; i < number_of_flats; i++) {
            to_return[i] = this->flats[i];
        }

        return to_return;
    }

    Flat FlatHouse::getFlat(size_t index) {
        return this->flats[index];
    }

    FlatHouse::~FlatHouse() {
        delete[] this->flats;
    }

} // CPP