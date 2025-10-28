/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class.
 */

#include "Inventory.h"
#include <iostream>

/**
 * @brief Adds a plant to the inventory.
 *
 * If the plant type doesn't exist, creates a new vector for it.
 * @param itemName The name of the plant type.
 * @param plant Pointer to the NurseryPlant to add.
 */
void Inventory::addPlant(const std::string& itemName, NurseryPlant* plant) {
    if (itemStock.find(itemName) == itemStock.end()) {
        itemStock[itemName] = std::vector<NurseryPlant*>();
    }
    itemStock[itemName].push_back(plant);
}

/**
 * @brief Removes a plant from the inventory.
 *
 * Removes the last plant of the specified type. If no plants remain, removes the entry.
 * @param itemName The name of the plant type to remove from.
 */
NurseryPlant* Inventory::removePlant(const std::string& itemName) {
    auto it = itemStock.find(itemName);
    if (it != itemStock.end() && !it->second.empty()) {
        NurseryPlant* plant = it->second.back();
        it->second.pop_back();
        

        if (it->second.empty()) {
            itemStock.erase(it);

        }
        return plant;
    } else {
        std::cout << "No plants of this type in inventory to remove.\n";
        return nullptr;
    }
}

/**
 * @brief Displays the current inventory.
 *
 * Prints each plant type and its stock count.
 */
void Inventory::displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& pair : itemStock) {
        std::cout << "Item: " << pair.first << ", Stock: " << pair.second.size() << "\n";
    }
}
