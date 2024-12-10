#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Transport.h"
#include "Truck.h"
#include "Bus.h"

// Функція для перевірки, чи рядок не порожній
bool isValidName(const std::string& name) {
    return !name.empty();
}

// Функція для перевірки, чи введено дійсне позитивне число
bool isValidPositiveNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return std::stoi(str) > 0;
}

// Функція для введення і перевірки числового вибору меню
int getMenuChoice() {
    std::string input;
    while (true) {
        std::cout << "\nМеню:\n1. Додати вантажівку\n2. Додати автобус\n3. Зберегти дані\n4. Завантажити дані\n5. Вийти\n";
        std::getline(std::cin, input);

        if (isValidPositiveNumber(input)) {
            int choice = std::stoi(input);
            if (choice >= 1 && choice <= 5) {
                return choice;
            }
        }
        std::cout << "Невірний вибір. Введіть число від 1 до 5.\n";
    }
}

// Функція для введення і перевірки назви
std::string getValidatedName(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidName(input)) {
            return input;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }
}

// Функція для введення і перевірки числового значення
int getValidatedPositiveNumber(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidPositiveNumber(input)) {
            return std::stoi(input);
        } else {
            std::cout << "Введіть дійсне позитивне число. Спробуйте ще раз.\n";
        }
    }
}

// Функція для збереження даних у файл
void saveToFile(const std::string& filename, const std::vector<Transport*>& vehicles) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Помилка відкриття файлу для запису." << std::endl;
        return;
    }
    for (const auto& vehicle : vehicles) {
        vehicle->saveToFile(ofs);
    }
    ofs.close();
    std::cout << "Дані успішно збережено у файл." << std::endl;
}

// Функція для завантаження даних з файлу
void loadFromFile(const std::string& filename, std::vector<Transport*>& vehicles) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Помилка відкриття файлу для читання." << std::endl;
        return;
    }

    // Очищення вектора перед завантаженням нових даних
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
    vehicles.clear();

    std::string type;
    while (ifs >> type) {
        Transport* vehicle = nullptr;
        if (type == "Truck") {
            std::string name;
            int firstValue, secondValue;
            if (ifs >> std::ws && std::getline(ifs, name, ' ') && ifs >> firstValue) {
                // Перевірка, чи є ще одне значення після першого числа
                if (ifs >> secondValue) {
                    // Якщо є два числа, перше використовується як частина назви
                    name += " " + std::to_string(firstValue);
                    vehicles.push_back(new Truck(name, secondValue));
                } else {
                    // Якщо є тільки одне число, воно використовується як вантажопідйомність
                    vehicles.push_back(new Truck(name, firstValue));
                }
            }
        } else if (type == "Bus") {
            std::string name;
            int firstValue, secondValue;
            if (ifs >> std::ws && std::getline(ifs, name, ' ') && ifs >> firstValue) {
                // Перевірка, чи є ще одне значення після першого числа
                if (ifs >> secondValue) {
                    // Якщо є два числа, перше використовується як частина назви
                    name += " " + std::to_string(firstValue);
                    vehicles.push_back(new Bus(name, secondValue));
                } else {
                    // Якщо є тільки одне число, воно використовується як місткість
                    vehicles.push_back(new Bus(name, firstValue));
                }
            }
        }
    }
    ifs.close();
    std::cout << "Дані успішно завантажено з файлу." << std::endl;

    // Вивід завантажених даних
    for (const auto& vehicle : vehicles) {
        vehicle->display();
    }
}


// Головна функція
int main() {
    std::vector<Transport*> vehicles;
    std::string filename = "vehicles.txt";

    int option;
    do {
        option = getMenuChoice();

        switch (option) {
            case 1: {
                std::string name = getValidatedName("Введіть назву вантажівки: ");
                int capacity = getValidatedPositiveNumber("Введіть вантажопідйомність (в кг): ");
                vehicles.push_back(new Truck(name, capacity));
                break;
            }
            case 2: {
                std::string name = getValidatedName("Введіть назву автобуса: ");
                int capacity = getValidatedPositiveNumber("Введіть місткість пасажирів: ");
                vehicles.push_back(new Bus(name, capacity));
                break;
            }
            case 3:
                saveToFile(filename, vehicles);
                break;
            case 4:
                loadFromFile(filename, vehicles);
                break;
        }
    } while (option != 5);

    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
