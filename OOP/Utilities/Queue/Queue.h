//
// Created by dgalytskyi on 6/24/24.
//

#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

#include <iostream>
#include <utility>

using namespace std;

namespace CPP {

    template<class T>
    class Queue {
    private:
        T *queue;
        size_t maxQueueLength;
        size_t queueLength;
    public:

        explicit Queue(int m) {
            this->maxQueueLength = m;
            this->queue = new T[maxQueueLength];
            this->queueLength = 0;
        }

        ~Queue() {
            delete[] queue;
        }

        void clear() {
            this->queueLength = 0;
        }

        bool isEmpty() {
            // Пуст?
            return this->queueLength == 0;
        }

        // Проверка на переполнение очереди
        bool isFull() {
            // Полон?
            return this->queueLength == this->maxQueueLength;
        }

        // Количество элементов в очереди
        int getCount() {
            // Количество присутствующих в стеке элементов
            return queueLength;
        }

        //демонстрация очереди
        void show() const {
            cout << "\n-------------------------------------\n";
            //демонстрация очереди
            for (int i = 0; i < this->queueLength; i++) {
                cout << queue[i] << " ";
            }
            cout << "\n-------------------------------------\n";
        }

        // Добавление элемента
        void add(T c) {
            // Если в очереди есть свободное место, то увеличиваем количество
            // значений и вставляем новый элемент
            if (!isFull())
                queue[queueLength++] = c;
        }

        // Извлечение элемента
        T *extract() {
            if (!isEmpty()) {
                T *temp = &(queue[0]);

                for (int i = 1; i < queueLength; i++)
                    queue[i - 1] = queue[i];

                queueLength--;

                return temp;
            } else {
                return nullptr;
            }
        }
    };

}

#endif //CPP_QUEUE_H
