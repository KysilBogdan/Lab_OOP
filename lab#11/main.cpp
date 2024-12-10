#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Transport.h"
#include "Truck.h"
#include "Bus.h"

// Функція для введення рядка з перевіркою на пустоту
std::string inputString(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Помилка: введіть непорожнє значення." << std::endl;
        }
    } while (input.empty());
    return input;
}

// Функція для введення цілих чисел з перевіркою на правильність
int inputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        // Перевірка, чи правильний ввід (число)
        if (std::cin.fail() || value < 0) {
            std::cin.clear(); // Очищення стану помилки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення залишкових символів у буфері вводу
            std::cout << "Помилка: введіть дійсне невід'ємне число." << std::endl;
        } else {
            // Очищення залишкових символів у буфері після успішного вводу числа
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

int main() {
    std::vector<Transport*> vehicles;

    // Введення кількості вантажівок
    int truckCount = inputInt("Введіть кількість вантажівок: ");
    for (int i = 0; i < truckCount; ++i) {
        std::cout << "Введіть дані для вантажівки №" << (i + 1) << std::endl;
        std::string name = inputString("Назва вантажівки: ");
        int year = inputInt("Рік випуску: ");
        int capacity = inputInt("Вантажопідйомність (кг): ");
        vehicles.push_back(new Truck(name, year, capacity));
    }

    // Введення кількості автобусів
    int busCount = inputInt("Введіть кількість автобусів: ");
    for (int i = 0; i < busCount; ++i) {
        std::cout << "Введіть дані для автобуса №" << (i + 1) << std::endl;
        std::string name = inputString("Назва автобуса: ");
        int year = inputInt("Рік випуску: ");
        int capacity = inputInt("Кількість пасажирів: ");
        vehicles.push_back(new Bus(name, year, capacity));
    }

    // Виведення інформації про всі транспортні засоби
    std::cout << "\nІнформація про транспортні засоби:\n";
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
    }

    // Звільнення пам'яті
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
