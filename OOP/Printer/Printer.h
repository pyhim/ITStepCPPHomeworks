//
// Created by dgalytskyi on 6/24/24.
//

#ifndef CPP_PRINTER_H
#define CPP_PRINTER_H

#include "../Utilities/Queue/Queue.h"
#include <string>
#include <ctime>

using namespace std;

namespace CPP {

    class Printer {
    private:
        Queue<string> statistic;
        Queue<string> to_print;

        void addEntry(string clientName);

    public:
        Printer();

        explicit Printer(size_t maxLength);

        void addToPrintQueue(string clientName, string data);

        void print_statistic() const;

        void print();
    };

} // CPP

#endif //CPP_PRINTER_H
