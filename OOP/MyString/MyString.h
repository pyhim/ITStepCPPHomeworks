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

        MyString& operator=(const MyString& other);

        void input();

        void output() const;

        void myStrcpy(const MyString &other);

        bool myStrstr(const char *string) const;

        int myChr(char c) const;

        long myStrlen() const;

        void myConcat(const MyString &other);

        void myDelChr(char c);

        int myStrCmp(const MyString &other) const;

        MyString operator+(MyString &other) const;

        void operator+=(MyString &other);

        int getInstances() const;
    };

} // CPP

#endif //CPP_MYSTRING_H
