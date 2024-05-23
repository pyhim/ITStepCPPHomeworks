#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {
        this->numerator = 0;
        this->denominator = 0;
    }

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    static Fraction add_fractions(Fraction first, Fraction second) {
        Fraction result{
            first.numerator + second.numerator,
            first.denominator
        };

        return result;
    }

    static Fraction subtract_fractions(Fraction first, Fraction second) {
        Fraction result{
            first.numerator - second.numerator,
            first.denominator
        };

        return result;
    }

    static Fraction multiply_fractions(Fraction first, Fraction second) {
        Fraction result{
            first.numerator + second.numerator,
            first.denominator + second.denominator
        };

        return result;
    }

    static Fraction divide_fractions(Fraction first, Fraction second) {
        Fraction result{
            first.numerator + second.denominator,
            first.denominator + second.numerator
        };

        return result;
    }

    void print_fraction() const {
        cout << this->numerator << '/' << this->denominator << endl;
    }

    static void print_fraction(Fraction fraction) {
        cout << fraction.numerator << '/' << fraction.denominator << endl;
    }

    ~Fraction() {
        cout << "Destructor" << endl;
    }
};
/*
int main() {
    Fraction fraction1{2, 5};
    Fraction fraction2{6, 7};

    fraction1.print_fraction();
    fraction2.print_fraction();

    Fraction::print_fraction(Fraction::add_fractions(fraction1, fraction2));
    Fraction::print_fraction(Fraction::subtract_fractions(fraction1, fraction2));
    Fraction::print_fraction(Fraction::multiply_fractions(fraction1, fraction2));
    Fraction::print_fraction(Fraction::divide_fractions(fraction1, fraction2));
}
*/