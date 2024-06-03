// #include "OOP/Reservoir/Reservoir.h"
#include <iostream>
#include "OOP/Account/Account.h"

using namespace CPP;

int main() {
    Account account("sasdfsadf", "1243fadsfasdf", 0.23);
    Account account1, account2, account3;

    account.makeDeposit(25600.54);
    std::cout << account.exchangeToDollars();
    std::cout << account.getCreatedInstances();

    return 0;
}
