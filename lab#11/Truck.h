#ifndef TRUCK_H
#define TRUCK_H

#include "Transport.h"

class Truck : public Transport {
private:
    int payloadCapacity;

public:
    Truck(std::string name, int year, int capacity) : Transport(name, year), payloadCapacity(capacity) {}
    virtual ~Truck() {}

    virtual void displayInfo() const override {
        std::cout << "Truck: " << name << ", Year: " << yearOfManufacture
                  << ", Payload Capacity: " << payloadCapacity << " kg" << std::endl;
    }
};

#endif // TRUCK_H
