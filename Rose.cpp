#include "Rose.h"
#include <iostream>

Rose::Rose(const std::string& color, double price) : FloweringPlant("Rose","High Maintenance",color, price){
      std::cout << "🌹 A " << color << " Rose has been planted.\n";
}

Rose::Rose(){
    : FloweringPlant("Rose", "High Maintenance", 0.0, 250.0) {
    std::cout << "🌹 Rose planted.\n";
};

void Rose::displayInfo() const {
    std::cout << "Rose (" << color << ") - " << Tree::maintenanceType << " Flowering Plant.\n";
}

std::string Rose::getDescription() {

    return NurseryPlant::description;
};

double Rose::calculateCost() {
    return NurseryPlant::basePrice;
};