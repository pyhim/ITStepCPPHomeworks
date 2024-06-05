//
// Created by dgalytskyi on 6/4/24.
//

#include "Reservoir.h"
#include "reservoir_test.h"
#include "../Utilities/DynamicArray/DynamicArray.h"

namespace CPP {
    // TODO: Fix segmentation fault
    void reservoir_test() {
        const size_t SIZE = 3;
        Reservoir array[SIZE]{
                Reservoir("Sea", 123.3, 54534.2, 1244.43),
                Reservoir("Lake", 22.1, 321.1, 323.7),
        };
        DynamicArray<Reservoir> dynamicArray(array, SIZE);

        dynamicArray.append(Reservoir("Sea", 854.3, 953.1, 43.9));
        std::cout << "End";
    }
}

