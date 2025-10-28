#include "Inventory.h"
#include <iostream>

Inventory::Inventory(const std::string& name, NurseryMediator* med) 
    : Participant(name, med) {

    plantStock["Rose"] = 25;
    plantStock["Baobab Tree"] = 5;
    plantStock["Lavender"] = 15;
    plantStock["Succulent"] = 30;
}

void Inventory::addPlant(const std::string& plantName, int quantity) {
    plantStock[plantName] += quantity;
    send("added " + std::to_string(quantity) + " " + plantName + " plants to inventory");
}

void Inventory::removePlant(const std::string& plantName, int quantity) {
    if (hasStock(plantName, quantity)) {
        plantStock[plantName] -= quantity;
        send("removed " + std::to_string(quantity) + " " + plantName + " plants from inventory");
    } else {
        send("ERROR: Not enough stock of " + plantName + " to remove " + std::to_string(quantity));
    }
}

void Inventory::checkStock(const std::string& plantName) {
    int stock = getStockCount(plantName);
    send("checked stock for " + plantName + " - " + std::to_string(stock) + " available");
}

void Inventory::displayStock() {
    std::cout << "=== CURRENT INVENTORY ===" << std::endl;
    for (const auto& item : plantStock) {
        std::cout << "- " << item.first << ": " << item.second << " units" << std::endl;
    }
    std::cout << "=========================" << std::endl;
}

bool Inventory::hasStock(const std::string& plantName, int quantity) {
    return plantStock.count(plantName) && plantStock[plantName] >= quantity;
}

int Inventory::getStockCount(const std::string& plantName) {
    return plantStock.count(plantName) ? plantStock[plantName] : 0;
}