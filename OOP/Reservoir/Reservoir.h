//
// Created by dgalytskyi on 6/1/24.
//

#ifndef CPP_RESERVOIR_H
#define CPP_RESERVOIR_H

namespace CPP {

    class Reservoir {
    private:
        const char *name;
        double height;
        double width;
        double depth;
    public:
        Reservoir();

        Reservoir(const char *name, double height, double width, double depth);

        Reservoir(const Reservoir& other);

        Reservoir& operator=(const Reservoir& other);

        ~Reservoir();

        double volume() const;

        double square() const;

        bool isEqual(const Reservoir& other);

        double largestSquare(const Reservoir& other);

        [[nodiscard]] double getHeight() const;

        void setHeight(double height);

        [[nodiscard]] double getWidth() const;

        void setWidth(double width);

        [[nodiscard]] double getDepth() const;

        void setDepth(double depth);
    };

} // CPP

#endif //CPP_RESERVOIR_H
