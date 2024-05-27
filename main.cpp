#include "OOP/construct_destruct/Car.h"

using CPP::Car;

int main() {
    Car car1;
    Car car2 = car1;

    car1.print();
    car2.print();
}
