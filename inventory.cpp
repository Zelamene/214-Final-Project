#include "Inventory.h"

Inventory::Inventory() {
}
Inventory::~Inventory() {
}
void Inventory::addPlant(const std::string& itemName, NurseryPlant* plant) {
    if (itemStock.find(itemName) == itemStock.end()) {
        itemStock[itemName] = std::vector<NurseryPlant*>();
    }
    itemStock[itemName].push_back(plant);
    return;
}