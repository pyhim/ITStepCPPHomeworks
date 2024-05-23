#include <iostream>
#include <cstring>

using namespace std;

struct Point {
    char letter;
    int x;
    int y;
};

struct Rectangle {
    Point A;
    Point B;
};

struct Person {
    char *name;
    char *surname;
    int age;
};

struct Fraction {
    int numerator;
    int denominator;
};

void init_person(Person &person) {
    char buff[20];
    int age;

    cout << "Enter name: ";
    cin >> buff;
    person.name = new char[strlen(buff) + 1];
    strcpy(person.name, buff);

    cout << "Enter surname: ";
    cin >> buff;
    person.surname = new char[strlen(buff) + 1];
    strcpy(person.surname, buff);

    cout << "Enter age: ";
    cin >> age;
    person.age = age;
}

void print_person(Person &person) {
    cout << "Name: " << person.name
         << "\nSurname: " << person.surname
         << "\nAge: " << person.age << endl;
}

void del_person(Person &person) {
    delete[] person.name;
    delete[] person.surname;
}

void init_point(Point &point, char letter) {
    point.x = rand() % 20;
    point.y = rand() % 20;
    point.letter = letter;
}

void print_point(Point &point) {
    cout << point.letter << " -> x: " << point.x << endl
         << point.letter << " -> y: " << point.y << endl;
}

void print_rectangle(Rectangle &rectangle) {
    print_point(rectangle.A);
    print_point(rectangle.B);
}

char parallel_to(Point &A, Point &B) {
    char result;

    if (A.x == B.x) {
        result = 'x';
    } else if (A.y == B.y) {
        result = 'y';
    } else {
        result = '0';
    }

    return result;
}

bool in_rectangle(Rectangle &rectangle, Point point) {
    if (point.x >= rectangle.A.x && point.x <= rectangle.B.x && point.y >= rectangle.A.y && point.y <= rectangle.B.y) {
        return true;
    } else {
        return false;
    }
}

// Левая точка по координатам должна быть ниже правой, если это не так, точки меняют позицию.
void normalize_rectangle(Rectangle &rectangle) {
    if (rectangle.A.y > rectangle.B.y) {
        Point temp = rectangle.A;
        rectangle.A = rectangle.B;
        rectangle.B = temp;
        rectangle.A.letter = 'A';
        rectangle.B.letter = 'B';

        cout << "Normalized rectangle: " << endl;
        print_rectangle(rectangle);
    }
}

void move_rectangle(Rectangle &rectangle) {
    char where;
    int value;

    cout << "Move (u)p, (d)own, (l)eft, (r)ight?: ";
    cin >> where;
    cout << "For how much cm do you want to move?: ";
    cin >> value;

    if (where == 'u') {
        rectangle.A.y += value;
        rectangle.B.y += value;
    } else if (where == 'd') {
        rectangle.A.y -= value;
        rectangle.B.y -= value;
    } else if (where == 'l') {
        rectangle.A.x -= value;
        rectangle.B.x -= value;
    } else if (where == 'r') {
        rectangle.A.x += value;
        rectangle.B.x += value;
    } else {
        cout << "Error";
    }

    cout << "Moved rectangle: " << endl;
    print_rectangle(rectangle);
}

void resize_rectangle(Rectangle &rectangle) {
    Point A;
    Point B;
    A.letter = 'A';
    B.letter = 'B';

    cout << "(Divide by space)"
         << "\nEnter new coordinates for A: ";
    cin >> A.x >> A.y;
    cout << "Enter new coordinates for B: ";
    cin >> B.x >> B.y;

    rectangle.A = A;
    rectangle.B = B;

    print_rectangle(rectangle);
}

void print_fraction(Fraction fraction) {
    cout << fraction.numerator << '/' << fraction.denominator << endl;
}

Fraction add_fractions(Fraction first, Fraction second) {
    Fraction result;

    result.numerator = first.numerator + second.numerator;
    result.denominator = first.denominator;

    return result;
}

Fraction subtract_fractions(Fraction first, Fraction second) {
    Fraction result;

    result.numerator = first.numerator - second.numerator;
    result.denominator = first.denominator;

    return result;
}

Fraction multiply_fractions(Fraction first, Fraction second) {
    Fraction result;

    result.numerator = first.numerator + second.numerator;
    result.denominator = first.denominator + second.denominator;

    return result;
}

Fraction divide_fractions(Fraction first, Fraction second) {
    Fraction result;

    result.numerator = first.numerator + second.denominator;
    result.denominator = first.denominator + second.numerator;

    return result;
}

int main() {
    srand(time(0));

    Point A;
    Point B;
    Point C{1, 3, 'C'};

    init_point(A, 'A');
    init_point(B, 'B');
    print_point(A);
    print_point(B);
    cout << parallel_to(A, B) << endl;

    A.x = 10, A.y = 5;
    B.x = -10, B.y = -5;
    Rectangle rectangle{A, B};

    print_rectangle(rectangle);
    cout << in_rectangle(rectangle, C) << endl;
    normalize_rectangle(rectangle);
    move_rectangle(rectangle);
    resize_rectangle(rectangle);

    Person person;
    init_person(person);
    print_person(person);
    del_person(person);

    Fraction first{1, 2};
    Fraction second{3, 4};

    print_fraction(add_fractions(first, second));
    print_fraction(subtract_fractions(first, second));
    print_fraction(multiply_fractions(first, second));
    print_fraction(divide_fractions(first, second));
}
