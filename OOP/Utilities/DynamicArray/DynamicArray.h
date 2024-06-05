//
// Created by dgalytskyi on 6/4/24.
//

#ifndef CPP_DYNAMICARRAY_H
#define CPP_DYNAMICARRAY_H

#include <iostream>

namespace CPP {

    template<class T>
    class DynamicArray {
    private:
        class ArrayItem {
        private:
            T *ptrToItem;
        public:
            ArrayItem();

            explicit ArrayItem(const T &item);

            ArrayItem(const ArrayItem &other);

            ArrayItem& operator=(const ArrayItem& other);

            ~ArrayItem();

            void change(T item);

            void clear();

            T getItem() const;
        };

        size_t size;
        ArrayItem *array;
    public:
        DynamicArray();

        explicit DynamicArray(size_t init);

        DynamicArray(T *array, size_t size);

        ~DynamicArray();

        DynamicArray(const DynamicArray &other);

        DynamicArray& operator=(const DynamicArray &other);

        void append(T item);

        T pop(size_t index);

        T get(size_t index) const;

        void set(T item, size_t index);

        void remove(size_t index);

        void print() const;
    };

} // CPP

#include "DynamicArray.tpp"

#endif //CPP_DYNAMICARRAY_H
