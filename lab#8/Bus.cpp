#include "Bus.h"
#include <iostream>
#include <limits>

Bus::Bus(std::string n, double c, int cap) : Transport(n, c, cap) {}

Bus::~Bus() {}

void Bus::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введіть назву автобуса: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Назва не може бути порожньою. Введіть знову: ";
        std::getline(std::cin, name);
    }

    std::cout << "Введіть вартість автобуса: ";
    while (!(std::cin >> cost) || cost < 0) {
        std::cout << "Введіть позитивне число для вартості: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setCost(cost);

    std::cout << "Введіть пасажирську місткість автобуса: ";
    while (!(std::cin >> capacity) || capacity < 0) {
        std::cout << "Введіть позитивне ціле число для пасажирської місткості: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setCapacity(capacity);
}

void Bus::display() const {
    std::cout << "Автобус: " << name << "\nВартість: " << cost << "\nПасажирська місткість: " << capacity << " осіб\n";
}
