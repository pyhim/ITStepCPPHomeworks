//
// Created by dgalytskyi on 6/4/24.
//

namespace CPP {
    template<class T>
    void arrcpy(T *dest, T *src, size_t src_size) {
        for (int i = 0; i < src_size; i++) {
            dest[i] = src[i];
        }
    }

    template<class T>
    void arrcpy(T *dest, T *src, size_t src_from_index, size_t src_to_index) {
        for (; src_from_index <= src_to_index; src_from_index++) {
            dest[src_from_index] = src[src_from_index];
        }
    }

    template<class T>
    DynamicArray<T>::ArrayItem::ArrayItem() : ptrToItem(nullptr)  {

    }

    template<class T>
    DynamicArray<T>::ArrayItem::ArrayItem(const T &item) {
        this->ptrToItem = new T(item);
    }

    template<class T>
    DynamicArray<T>::ArrayItem::~ArrayItem() {
        this->clear();
    }

    template<class T>
    DynamicArray<T>::ArrayItem::ArrayItem(const DynamicArray::ArrayItem &other) {
        this->clear();
        this->ptrToItem = other.ptrToItem;
    }

    template<class T>
    DynamicArray<T>::ArrayItem &DynamicArray<T>::ArrayItem::operator=(const DynamicArray::ArrayItem &other) {
        if (this == &other) {
            return *this;
        }

        this->clear();
        this->ptrToItem = other.ptrToItem;

        return *this;
    }

    template<class T>
    void DynamicArray<T>::ArrayItem::change(T item) {
        this->clear();

        this->ptrToItem = &item;
    }

    template<class T>
    void DynamicArray<T>::ArrayItem::clear() {
        delete this->ptrToItem;
    }

    template<class T>
    T DynamicArray<T>::ArrayItem::getItem() const {
        return *(this->ptrToItem);
    }

    template<class T>
    DynamicArray<T>::DynamicArray() : DynamicArray(10) {

    }

    template<class T>
    DynamicArray<T>::DynamicArray(T *array, size_t size) : array(new ArrayItem[size]), size(size) {
        for (int i = 0; i < size; i++) {
            this->array[i] = ArrayItem(array[i]);
        }
    }

    template<class T>
    DynamicArray<T>::DynamicArray(size_t init) : array(new ArrayItem[init]), size(init) {
        for (int i = 0; i < this->size; i++) {
            this->array[i] = ArrayItem();
        }
    }

    template<class T>
    DynamicArray<T>::~DynamicArray() {
        delete[] this->array;
    }

    template<class T>
    DynamicArray<T>::DynamicArray(const DynamicArray &other) : DynamicArray(other.size) {

    }

    template<class T>
    DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->array;

        this->array = new ArrayItem[other.size];
        this->size = other.size;
        arrcpy<ArrayItem>(this->array, other.array, this->size);

        return *this;
    }

    template<class T>
    void DynamicArray<T>::append(T item) {
        size_t new_size = this->size + 1;
        auto *new_array = new ArrayItem[new_size];

        arrcpy<ArrayItem>(new_array, this->array, this->size);
        new_array[new_size] = ArrayItem(item);

        delete[] this->array;

        this->array = new_array;
        this->size = new_size;
    }

    template<class T>
    T DynamicArray<T>::pop(size_t index) {
        T to_return = this->array[index].getItem();
        this->array[index].clear();

        return to_return;
    }

    template<class T>
    T DynamicArray<T>::get(size_t index) const {
        return this->array[index].getItem();
    }

    template<class T>
    void DynamicArray<T>::set(T item, size_t index) {
        this->array[index].change(item);
    }

    template<class T>
    void DynamicArray<T>::remove(size_t index) {
        size_t new_size = this->size - 1;
        size_t this_last_index = new_size;
        auto *new_array = new ArrayItem[new_size];

        if (index == 0) {
            size_t from_index = 1;
            arrcpy<ArrayItem>(new_array, this->array, from_index, this_last_index);
        } else if (index == this_last_index) {
            size_t from_index = 0;
            arrcpy<ArrayItem>(new_array, this->array, from_index, this_last_index - 1);
        } else {
            size_t from_index = 0;
            arrcpy<ArrayItem>(new_array, this->array, from_index, index - 1);
            arrcpy<ArrayItem>(new_array, this->array, index + 1, this_last_index);
        }

        delete[] this->array;

        this->array = new_array;
        this->size = new_size;
    }

    template<class T>
    void DynamicArray<T>::print() const {
        std::cout << "{ ";
        for (int i = 0; i < this->size; i++) {
            std::cout << this->array[i].getItem() << ", ";
        }
        std::cout << '}' << std::endl;
    }
} // CPP