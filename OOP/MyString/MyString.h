//
// Created by dgalytskyi on 6/10/24.
//

#ifndef CPP_MYSTRING_H
#define CPP_MYSTRING_H

namespace CPP {

    class MyString {
    private:
        const char *string;
        static int instances;
        long length;
    public:
        MyString();

        explicit MyString(long length);

        explicit MyString(const char *string);

        ~MyString();

        MyString(const MyString& other);

        MyString( MyString&& other) noexcept;

        MyString& operator=(const MyString& other);

        MyString& operator=(MyString&& other) noexcept;

        void input();

        void output() const;

        [[nodiscard]] const char *getString() const;

        [[nodiscard]] long getLength() const;

        void myStrcpy(const MyString &other);

        bool myStrstr(const char *string) const;

        [[nodiscard]] long myChr(char c) const;

        [[nodiscard]] long myStrlen() const;

        void myConcat(const MyString &other);

        void myDelChr(char c);

        [[nodiscard]] int myStrCmp(const MyString &other) const;

        MyString operator+(MyString &other) const;

        void operator+=(MyString &other);

        void operator+=(const char *string);

        void operator-=(char c);

        void operator*(int value);

        char operator[](long index);

        [[nodiscard]] static int getInstances();
    };

} // CPP

#endif //CPP_MYSTRING_H
