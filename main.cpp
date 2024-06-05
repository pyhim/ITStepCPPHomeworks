#include <iostream>
#include "OOP/Fraction/Fraction.h"

using namespace CPP;
using std::cout;

int main() {
    Fraction fraction1(5, 3), fraction2(2, 3);

    (fraction1 + fraction2).print();
    (fraction1 - fraction2).print();
    (fraction1 * fraction2).print();
    (fraction1 / fraction2).print();

    return 0;
}
