#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

class Transport {
protected:
    std::string name;
    double cost;
    int capacity;

public:
    Transport(std::string n = "", double c = 0.0, int cap = 0);
    virtual ~Transport();

    std::string getName() const;
    double getCost() const;
    int getCapacity() const;

    void setName(const std::string& n);
    void setCost(double c);
    void setCapacity(int cap);

    virtual void input() = 0;
    virtual void display() const = 0;
};

#endif
