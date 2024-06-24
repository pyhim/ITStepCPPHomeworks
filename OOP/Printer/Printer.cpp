//
// Created by dgalytskyi on 6/24/24.
//

#include "Printer.h"

#include <ctime>
#include <utility>

namespace CPP {
    const char *getTime() {
        char *result;

        time_t unixTime = time(nullptr);
        result = ctime(&unixTime);

        return result;
    }

    void Printer::addEntry(string clientName) {
        string time = getTime(), to_add = std::move(clientName) + ' ' + time;

        this->statistic.add(to_add);
    }

    Printer::Printer() : statistic(50), to_print(50) {

    }

    Printer::Printer(size_t maxLength) : statistic(maxLength), to_print(maxLength) {

    }

    void Printer::addToPrintQueue(string clientName, string data) {
        this->addEntry(std::move(clientName));

        this->to_print.add(std::move(data));
    }

    void Printer::print_statistic() const {
        this->statistic.show();
    }

    void Printer::print() {
        for (size_t i = 0; i < this->to_print.getCount() + 2; i++) {
            cout << *(this->to_print.extract()) << endl;
        }
    }
} // CPP