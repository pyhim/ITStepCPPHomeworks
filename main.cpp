#include "OOP/FlatHouse/headers/FlatHouse.h"

using namespace CPP;

int main() {
    Person person1("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006));
    Person person2("123412312", "Dmytro", "Galytskyi", "Ruslanovych", Date(14, 10, 2006));
    Person family[2]{person1, person2};
    Flat flat1(family, 2, 15.1);
    Flat flat2(family, 2, 16.2);
    Flat flats[2]{flat1, flat2};
    FlatHouse house(flats, 2);

    return 0;
}
