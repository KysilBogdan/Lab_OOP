#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <iostream>

class Queue {
private:
    std::vector<int> elements;

public:
    // Конструктор
    Queue(const std::vector<int>& elems);

    // Оператор порівняння <= для порівняння добутків елементів
    bool operator<=(const Queue& other) const;

    // Оператор += для додавання елементів іншої черги
    Queue& operator+=(const Queue& other);

    // Метод для обчислення добутку елементів
    int product() const;

    // Метод для виведення елементів черги
    void print() const;
};

#endif
