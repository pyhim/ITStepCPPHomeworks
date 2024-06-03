//
// Created by dgalytskyi on 6/3/24.
//

#include <iostream>
#include "Account.h"
#include "../Utilities/strdup_new.h"

namespace CPP {
    int Account::createdInstances = 0;

    Account::Account(const char *surname, const char *serialNumber, double percent)
    : surname(strdup(surname)), serialNumber(strdup(serialNumber)), interest(percent), sum(0) {
        Account::createdInstances++;
    }

    Account::Account() : Account(nullptr, nullptr, 0) {
        Account::createdInstances++;
    }

    void Account::changeAccountHolder(const char *surname, const char *serialNumber) {
        delete[] surname;
        delete[] serialNumber;

        this->surname = strdup(surname);
        this->serialNumber = strdup(serialNumber);
    }

    double Account::makeWithdrawal(double amount) {
        if (amount > this->sum) {
            return 0;
        }

        this->sum -= amount;
        return amount;
    }

    void Account::makeDeposit(double amount) {
        this->sum += amount;
    }

    double Account::getSum() const {
        return sum;
    }

    void Account::chargeInterest(double toAdd) {
        this->interest += toAdd;
    }

    double Account::exchangeToDollars() const {
        double currency = 42.50;

        return sum / currency;
    }

    double Account::exchangeToEuros() const {
        double currency = 40.50;

        return this->sum / currency;
    }

    void Account::printSum() const {
        std::cout << this->sum;
    }

    int Account::getCreatedInstances() {
        return Account::createdInstances;
    }

    Account::~Account() {
        delete[] surname;
        delete[] serialNumber;

        Account::createdInstances--;
    }

    const char *Account::getSerialNumber() const {
        return this->serialNumber;
    }

    double Account::getInterest() const {
        return this->interest;
    }

    const char *Account::getSurname() const {
        return this->surname;
    }
} // CPP