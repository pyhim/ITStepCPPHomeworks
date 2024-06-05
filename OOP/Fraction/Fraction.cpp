//
// Created by dgalytskyi on 6/5/24.
//

#include <iostream>
#include "Fraction.h"

namespace CPP {
    Fraction::Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction Fraction::operator+(Fraction &other) {
        return Fraction(this->numerator + other.numerator, this->denominator);
    }

    Fraction Fraction::operator-(Fraction &other) {
        return Fraction(this->numerator - other.numerator, this->denominator);
    }

    Fraction Fraction::operator*(Fraction &other) {
        return Fraction(this->numerator + other.numerator, this->denominator + other.denominator);
    }

    Fraction Fraction::operator/(Fraction &other) {
        return Fraction(this->numerator + other.denominator, this->denominator + other.numerator);
    }

    void Fraction::print() const {
        std::cout << this->numerator << '/' << this->denominator << std::endl;
    }
} // CPP