//
// Created by dgalytskyi on 6/26/24.
//

#ifndef CPP_LINKEDLIST_H
#define CPP_LINKEDLIST_H

#include <iostream>
using namespace std;

namespace CPP {

    struct Element
    {
        // Данные
        char data;
        // Адрес следующего элемента списка
        Element * Next;
    };

    // Односвязный список
    class List
    {
        // Адрес головного элемента списка
        Element * Head;
        // Адрес головного элемента списка
        Element * Tail;
        // Количество элементов списка
        int Count;

    public:
        // Конструктор
        List();
        // Деструктор
        ~List();

        // Добавление элемента в список
        // (Новый элемент становится последним)
        void Add(char data);

        // Удаление элемента списка
        // (Удаляется головной элемент)
        void Del();
        // Удаление всего списка
        void DelAll();

        // Распечатка содержимого списка
        // (Распечатка начинается с головного элемента)
        void Print();

        // Получение количества элементов, находящихся в списке
        int GetCount();

        void AddIndex(char c, int i);

        void DelIndex(int index);

        int search(char c);
    };

    List::List()
    {
        // Изначально список пуст
        Head = Tail = nullptr;
        Count = 0;
    }

    List::~List()
    {
        // Вызов функции удаления
        DelAll();
    }

    int List::GetCount()
    {
        // Возвращаем количество элементов
        return Count;
    }

    void List::Add(char data)
    {
        // создание нового элемента
        Element * temp = new Element;

        // заполнение данными
        temp->data = data;
        // следующий элемент отсутствует
        temp->Next = nullptr;
        // новый элемент становится последним элементом списка
        // если он не первый добавленный
        if(Head!=nullptr){
            Tail->Next=temp;
            Tail = temp;
        }
            // новый элемент становится единственным
            // если он первый добавленный
        else{
            Head=Tail=temp;
        }
    }

    void List::Del()
    {
        // запоминаем адрес головного элемента
        Element * temp = Head;
        // перебрасываем голову на следующий элемент
        Head = Head->Next;
        // удаляем бывший головной элемент
        delete temp;
    }

    void List::DelAll()
    {
        // Пока еще есть элементы
        while(Head != 0)
            // Удаляем элементы по одному
            Del();
    }

    void List::Print()
    {
        // запоминаем адрес головного элемента
        Element * temp = Head;
        // Пока еще есть элементы
        while(temp != 0)
        {
            // Выводим данные
            cout << temp->data << " ";
            // Переходим на следующий элемент
            temp = temp->Next;
        }

        cout << "\n\n";
    }

    void List::AddIndex(char c, int i) {
        int count = 1;
        Element *temp = this->Head;

        while(count < i) {
            temp = temp->Next;
            i++;
        }

        auto *newElement = new Element;
        newElement->data = c;
        newElement->Next = temp->Next;
        temp->Next = newElement;
    }

    void List::DelIndex(int index) {
        Element *previousElement = this->Head;
        Element *toDelete = nullptr;

        for (int i = 1; i < index; i++) {
            previousElement = previousElement->Next;
        }

        toDelete = previousElement->Next;
        previousElement->Next = toDelete->Next;

        delete toDelete;
    }

    int List::search(char c) {
        Element *checkingElement = this->Head;
        int count = 0;

        while (checkingElement != this->Tail) {
            if (checkingElement->data == c) {
                return count;
            }

            checkingElement = checkingElement->Next;
            count++;
        }

        return -1;
    }

// Тестовый пример
    void main()
    {
        // Создаем объект класса List
        List lst;

        // Тестовая строка
        char s[] = "Hello, World !!!\n";
        // Выводим строку
        cout << s << "\n\n";
        // Определяем длину строки
        int len = strlen(s);
        // Загоняем строку в список
        for(int i = 0; i < len; i++)
            lst.Add(s[i]);
        // Распечатываем содержимое списка
        lst.Print();
        // Удаляем три элемента списка
        lst.Del();
        lst.Del();
        lst.Del();
        //Распечатываем содержимое списка
        lst.Print();
    }


} // CPP

#endif //CPP_LINKEDLIST_H
