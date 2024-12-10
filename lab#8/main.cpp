#include <iostream>
#include <vector>
#include <iomanip>
#include "Transport.h"
#include "Truck.h"
#include "Bus.h"

int main() {
    std::vector<Transport*> transports;
    int truckCount, busCount;

    // Введення кількості вантажівок
    std::cout << "Скільки вантажівок ви хочете додати? ";
    while (!(std::cin >> truckCount) || truckCount < 1) {
        std::cout << "Введіть позитивне ціле число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Введення кількості автобусів
    std::cout << "Скільки автобусів ви хочете додати? ";
    while (!(std::cin >> busCount) || busCount < 1) {
        std::cout << "Введіть позитивне ціле число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Створення об'єктів вантажівок
    for (int i = 0; i < truckCount; ++i) {
        Truck* truck = new Truck();
        truck->input();
        transports.push_back(truck);
    }

    // Створення об'єктів автобусів
    for (int i = 0; i < busCount; ++i) {
        Bus* bus = new Bus();
        bus->input();
        transports.push_back(bus);
    }

    // Виведення заголовку перед даними
    std::cout << "---------------------\n";
    for (const auto& transport : transports) {
        transport->display();
        std::cout << "---------------------\n";
    }

    // Обчислення загальної та середньої вартості
    double totalCost = 0.0;
    for (const auto& transport : transports) {
        totalCost += transport->getCost();
    }
    double averageCost = (transports.size() > 0) ? (totalCost / transports.size()) : 0.0;

    // Виведення загальної та середньої вартості
    std::cout << "Загальна вартість транспорту: " << std::fixed << std::setprecision(2) << totalCost << " грн\n";
    std::cout << "Середня вартість транспорту: " << std::fixed << std::setprecision(2) << averageCost << " грн\n";

    // Звільнення пам'яті
    for (auto& transport : transports) {
        delete transport;
    }

    return 0;
}
