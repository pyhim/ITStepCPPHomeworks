//
// Created by dgalytskyi on 6/5/24.
//

#ifndef CPP_FRACTION_H
#define CPP_FRACTION_H

namespace CPP {

    class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);

        Fraction operator+(Fraction &other);

        Fraction operator-(Fraction &other);

        Fraction operator*(Fraction &other);

        Fraction operator/(Fraction &other);

        void print() const;
    };

} // CPP

#endif //CPP_FRACTION_H
