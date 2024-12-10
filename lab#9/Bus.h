#ifndef BUS_H
#define BUS_H

#include "Transport.h"

class Bus : public Transport {
public:
    Bus(std::string n = "", double c = 0.0, int cap = 0);
    virtual ~Bus();

    void input() override;
    void display() const override;

    friend class TransportManager;  // Дружній клас
};

#endif
