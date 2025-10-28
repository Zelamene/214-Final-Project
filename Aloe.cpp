#include "Aloe.h"
#include <iostream>


Aloe::Aloe(double height, double price)
    : Tree("Aloe", "Low Maintenance", height,price) { 
    std::cout << "🌿 Aloe planted.\n";
}
Aloe::Aloe()
    : Tree("Aloe", "Low Maintenance", 0.0, 250.0) {
    std::cout << "🌿 Aloe planted.\n";
}
std::string Aloe::getDescription() const {
    return NurseryPlant::description;
};
double Aloe::calculateCost() {
    return NurseryPlant::basePrice;
};
void Aloe::displayInfo() const {
    std::cout << "Aloe - " << Tree::maintenanceType << " Tree, Height: " << height << " m.\n";
}
Aloe::~Aloe() {
    
};