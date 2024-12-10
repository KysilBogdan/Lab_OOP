#ifndef TRUCK_H
#define TRUCK_H

#include "Transport.h"

class Truck : public Transport {
public:
    Truck(std::string n = "", double c = 0.0, int cap = 0);
    virtual ~Truck();

    void input() override;
    void display() const override;
};

#endif
