//
// Created by dgalytskyi on 6/1/24.
//

#include <cstring>
#include "../Utilities/strdup_new.h"
#include "Reservoir.h"

namespace CPP {
    Reservoir::Reservoir() : Reservoir(nullptr, 0, 0, 0) {

    }

    Reservoir::Reservoir(const char *name, double height, double width, double depth)
    : name(strdup(name)), height(height), width(width), depth(depth) {

    }

    Reservoir::Reservoir(const Reservoir &other)
    : name(strdup(other.name)), height(other.height), width(other.width), depth(other.depth) {

    }


    Reservoir& Reservoir::operator=(const Reservoir &other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;

        this->name = strdup(other.name);
        this->height = other.height;
        this->width = other.width;
        this->depth = other.depth;

        return *this;
    }

    Reservoir::~Reservoir() {
        delete[] name;
    }

    double Reservoir::volume() const {
        return this->height * this->width * this->depth;
    }

    double Reservoir::square() const {
        return this->width * this->width;
    }

    bool Reservoir::isEqual(const Reservoir &other) {
        return strcmp(other.name, this->name) == 0;
    }

    double Reservoir::largestSquare(const Reservoir &other) const {
        double this_square = this->square();
        double other_square = other.square();

        return this_square > other_square ? this_square : other_square;
    }

    double Reservoir::getHeight() const {
        return height;
    }

    void Reservoir::setHeight(double height) {
        Reservoir::height = height;
    }

    double Reservoir::getWidth() const {
        return width;
    }

    void Reservoir::setWidth(double width) {
        Reservoir::width = width;
    }

    double Reservoir::getDepth() const {
        return depth;
    }

    void Reservoir::setDepth(double depth) {
        Reservoir::depth = depth;
    }
} // CPP