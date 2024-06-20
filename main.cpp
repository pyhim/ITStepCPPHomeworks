#include <iostream>
#include "OOP/Car/Car.h"

using namespace CPP;
using namespace std;

int main() {
    Car car1("Audi", "Red", "Germany", 2023, 50000);
    Car car2("BMW", "Blue", "Germany", 2019, 30000);
    
    /*cout << car1 << endl;
    cin >> car1;
    cout << car1 << endl;
    
	car1 += 1000; // увеличиваем стоимость на 1000
    cout << car1;
	car1 -= 1000; // уменьшаем стоимость на 1000
    cout << car1;

	++car1; // увеличиваем год на 1
    cout << car1;
	--car1; // уменьшаем год на 1
    cout << car1;

	double r = car1 - car2; // разность стоимости автомобилей
	double sum = car1 + car2; // сумма стоимости автомобилей , возвращается общая сумма
    
    cout << r << ' ' << sum << endl;*/

    Car car3 = std::move(car1), car4("Nissan", "Gray", "Japan",1231, 124123);
    cout << car3;
    cout << car4;

    car4 = std::move(car2);
    cout << car4;
}
