#include "OOP/FlatHouse/headers/FlatHouse.h"

using namespace CPP;

int main() {
    const size_t FLATS = 2, PERSONS = 2;

    Person family1[PERSONS]{
            Person("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006)),
            Person("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006))
    };
    Person family2[PERSONS]{
            Person("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006)),
            Person("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006))
    };
    Flat flats[FLATS]{
            Flat(family1, PERSONS),
            Flat(family2, PERSONS)
    };
    FlatHouse house(flats, FLATS);

    house.getFlat(0).getFamily()[0].print_credentials();

    return 0;
}
