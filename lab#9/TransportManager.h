#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Transport.h"
#include "Truck.h"
#include "Bus.h"
#include <vector>

class TransportManager {
public:
    static double calculateTotalCost(const std::vector<Transport*>& transports) {
        double totalCost = 0.0;
        for (const auto& transport : transports) {
            totalCost += transport->cost;  // Доступ до приватного члена
        }
        return totalCost;
    }

    static double calculateAverageCost(const std::vector<Transport*>& transports) {
        if (transports.empty()) return 0.0;
        return calculateTotalCost(transports) / transports.size();
    }
};

#endif
