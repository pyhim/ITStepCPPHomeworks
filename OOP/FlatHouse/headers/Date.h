//
// Created by dgalytskyi on 5/27/24.
//

#ifndef CPP_DATE_H
#define CPP_DATE_H

namespace CPP {

    class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year);

        Date();

        [[nodiscard]] int getDay() const;

        [[nodiscard]] int getMonth() const;

        [[nodiscard]] int getYear() const;

        void setDay(int day);

        void setMonth(int month);

        void setYear(int year);
    };

} // CPP

#endif //CPP_DATE_H
