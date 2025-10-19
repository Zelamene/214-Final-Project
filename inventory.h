#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <map>
#include "NurseryPlant.h"
class Inventory {
    private:

        std::map<std::string, std::vector<NurseryPlant*>> itemStock;

    public:
        Inventory()=default;
        ~Inventory()=default;
        void addPlant(const std::string& itemName, NurseryPlant* plant);
        void removePlant(const std::string& itemName);
        void displayInventory() const;
};

#endif