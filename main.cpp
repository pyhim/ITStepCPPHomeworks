#include <iostream>
#include "OOP/Car/Car.h"

using namespace CPP;
using namespace std;

int main() {
    Car car1("Audi", 2023, 50000), car2("BMW", 2019, 30000);
    
    cout << car1 << endl;
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
    
    cout << r << ' ' << sum << endl;
}
