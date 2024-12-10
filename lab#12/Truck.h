#ifndef TRUCK_H
#define TRUCK_H

#include "Transport.h"

class Truck : public Transport {
private:
    std::string name;
    int capacity;

public:
    Truck() = default;
    Truck(const std::string& name, int capacity) : name(name), capacity(capacity) {}

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Truck " << name << " " << capacity << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
    ifs >> std::ws; // Пропускаємо зайві пробіли
    std::getline(ifs, name, ' '); // Зчитуємо назву до пробілу
    ifs >> capacity; // Зчитуємо вантажопідйомність
}


    void display() const override {
        std::cout << "Вантажівка: Назва = " << name << ", Вантажопідйомність = " << capacity << " кг\n";
    }
};

#endif // TRUCK_H
