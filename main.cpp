#include "OOP/MyString/MyString.h"

using namespace CPP;

int main() {
    MyString str("hello precious wonderful world!");

    str -= 'h';
    str.output();
    str += " I said hello world!";
    str.output();
}
