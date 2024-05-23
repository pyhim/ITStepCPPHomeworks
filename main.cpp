#include "OOP/construct_destruct/Car.h"

using CPP::Car;

int main() {
    Car car1;
    Car car2("Toyota", "Japan", "Purple", 2007, 1233.1);

    car1.input();
    car1.print();
    car2.print();
}
