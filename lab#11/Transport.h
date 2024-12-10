#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

class Transport {
protected:
    std::string name;
    int yearOfManufacture;

public:
    Transport(std::string name, int year) : name(name), yearOfManufacture(year) {}
    virtual ~Transport() {}

    virtual void displayInfo() const {
        std::cout << "Transport: " << name << ", Year: " << yearOfManufacture << std::endl;
    }
};

#endif // TRANSPORT_H
