#include <iostream>
#include "OOP/Printer/Printer.h"

using namespace CPP;
using namespace std;

int main() {
    Printer printer;

    printer.addToPrintQueue("sadasdasd", "something");
    printer.addToPrintQueue("sfgfsdg", "somefgdfsg");
    printer.addToPrintQueue("shrhrthtr", "sdfgfdgthing");

    printer.print();

    printer.print_statistic();
}
