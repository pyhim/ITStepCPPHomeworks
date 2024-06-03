//
// Created by dgalytskyi on 6/3/24.
//

#ifndef CPP_ACCOUNT_H
#define CPP_ACCOUNT_H

namespace CPP {

    class Account {
    private:
        const char *surname;
        const char *serialNumber;
        static int createdInstances;
        double interest;
        double sum;
    public:
        Account(const char *surname, const char *serialNumber, double percent);

        Account();

        void changeAccountHolder(const char *surname, const char *serialNumber);

        double makeWithdrawal(double amount);

        void makeDeposit(double amount);

        void chargeInterest(double toAdd);

        [[nodiscard]] double exchangeToDollars() const;

        [[nodiscard]] double exchangeToEuros() const;

        void printSum() const;

        static int getCreatedInstances();

        [[nodiscard]] double getSum() const;

        ~Account();

        [[nodiscard]] const char *getSerialNumber() const;

        [[nodiscard]] double getInterest() const;

        [[nodiscard]] const char *getSurname() const;
    };

} // CPP

#endif //CPP_ACCOUNT_H
