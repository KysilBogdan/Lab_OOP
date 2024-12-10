#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <fstream>
#include <string>

class Transport {
public:
    virtual void saveToFile(std::ofstream& ofs) const = 0;
    virtual void loadFromFile(std::ifstream& ifs) = 0;
    virtual void display() const = 0;
    virtual ~Transport() = default;
};

#endif // TRANSPORT_H
