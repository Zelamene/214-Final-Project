#ifndef INVENTORY_H
#define INVENTORY_H

#include "Participant.h"
#include <string>
#include <map>

class Inventory : public Participant {
private:
    std::map<std::string, int> plantStock;
    
public:
    Inventory(const std::string& name, NurseryMediator* med = nullptr);
    
    void addPlant(const std::string& plantName, int quantity);
    void removePlant(const std::string& plantName, int quantity);
    void checkStock(const std::string& plantName);
    void displayStock();
    bool hasStock(const std::string& plantName, int quantity = 1);
    int getStockCount(const std::string& plantName);
};

#endif // INVENTORY_H