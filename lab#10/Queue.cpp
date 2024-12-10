#include "Queue.h"
#include <iostream>
#include <numeric>

Queue::Queue(const std::vector<int>& elems) : elements(elems) {}

bool Queue::operator<=(const Queue& other) const {
    int thisProduct = 1;
    for (int elem : elements) {
        thisProduct *= elem;
    }

    int otherProduct = 1;
    for (int elem : other.elements) {
        otherProduct *= elem;
    }

    return thisProduct <= otherProduct;
}

Queue& Queue::operator+=(const Queue& other) {
    for (int elem : other.elements) {
        elements.push_back(elem);
    }
    return *this;
}

int Queue::product() const {
    int prod = 1;
    for (int elem : elements) {
        prod *= elem;
    }
    return prod;
}

void Queue::print() const {
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
