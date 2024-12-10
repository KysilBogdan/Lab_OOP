#include "Truck.h"
#include <iostream>
#include <limits>

Truck::Truck(std::string n, double c, int cap) : Transport(n, c, cap) {}

Truck::~Truck() {}

void Truck::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введіть назву вантажівки: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Назва не може бути порожньою. Введіть знову: ";
        std::getline(std::cin, name);
    }

    std::cout << "Введіть вартість вантажівки: ";
    while (!(std::cin >> cost) || cost < 0) {
        std::cout << "Введіть позитивне число для вартості: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setCost(cost);

    std::cout << "Введіть вантажопідйомність вантажівки: ";
    while (!(std::cin >> capacity) || capacity < 0) {
        std::cout << "Введіть позитивне ціле число для вантажопідйомності: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setCapacity(capacity);
}

void Truck::display() const {
    std::cout << "Вантажівка: " << name << "\nВартість: " << cost << "\nВантажопідйомність: " << capacity << " кг\n";
}
