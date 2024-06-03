//
// Created by dgalytskyi on 6/2/24.
//

#include <cstring>
#include "strdup_new.h"

using std::strlen;
using std::memcpy;

namespace CPP {
    char* strdup(const char* str) {
        if (str == nullptr) {
            return nullptr;
        }

        size_t len = strlen(str) + 1;
        char* copy = new char[len];
        memcpy(copy, str, len);
        return copy;
    }
}
