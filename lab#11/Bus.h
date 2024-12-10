#ifndef BUS_H
#define BUS_H

#include "Transport.h"

class Bus : public Transport {
private:
    int passengerCapacity;

public:
    Bus(std::string name, int year, int capacity) : Transport(name, year), passengerCapacity(capacity) {}
    virtual ~Bus() {}

    virtual void displayInfo() const override {
        std::cout << "Bus: " << name << ", Year: " << yearOfManufacture
                  << ", Passenger Capacity: " << passengerCapacity << " people" << std::endl;
    }
};

#endif // BUS_H
