#include "Transport.h"
#include <iostream>
#include <limits>

Transport::Transport(std::string n, double c, int cap) : name(n), cost(c), capacity(cap) {}

Transport::~Transport() {}

std::string Transport::getName() const {
    return name;
}

double Transport::getCost() const {
    return cost;
}

int Transport::getCapacity() const {
    return capacity;
}

void Transport::setName(const std::string& n) {
    name = n;
}

void Transport::setCost(double c) {
    if (c >= 0)
        cost = c;
    else
        std::cout << "Вартість не може бути негативною!\n";
}

void Transport::setCapacity(int cap) {
    if (cap >= 0)
        capacity = cap;
    else
        std::cout << "Вантажопідйомність не може бути негативною!\n";
}
