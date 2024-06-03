//
// Created by dgalytskyi on 6/1/24.
//

#include "../Utilities/strdup_new.h"
#include "Reservoir.h"

namespace CPP {
    Reservoir::Reservoir() {

    }

    Reservoir::Reservoir(const char *name, double height, double width, double depth)
    : name(strdup(name)), height(height), width(width), depth(depth) {

    }

    Reservoir::Reservoir(const Reservoir &other) {

    }

    Reservoir Reservoir::operator=(const Reservoir &other) {
        if (this == &other) {
            return *this;
        }

        // TODO: write assignment operator override
    }

    Reservoir::~Reservoir() {

    }

    double Reservoir::volume() const {
        return 0;
    }

    double Reservoir::square() const {
        return 0;
    }

    bool Reservoir::isEqual(const Reservoir &other) {
        return false;
    }

    double Reservoir::largestSquare(const Reservoir &other) {
        return 0;
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