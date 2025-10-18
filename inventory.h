#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <map>
#include "NurseryPlant.h"
class Inventory {
    private:
        // Add private members for inventory management
        // NurseryPlant* plants;
        std::map<std::string, std::vector<NurseryPlant*>> itemStock; // Example: item name to stock count

    public:
        Inventory()=default;
        ~Inventory()=default;
        void addPlant(const std::string& itemName, NurseryPlant* plant);
        void removePlant(const std::string& itemName);
        void displayInventory() const;
};

#endif