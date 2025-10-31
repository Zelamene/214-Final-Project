#include "Baobab.h"
#include <iostream>

Baobab::Baobab(double height, double price)
    : Tree("Baobab", "High Maintenance", height , price){
    std::cout << "🌳 Baobab planted.\n";
}

Baobab::Baobab(){
    description = "Baobab";
    basePrice = 100.0;
};

void Baobab::displayInfo() const {
    std::cout << "Baobab - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}

std::string Baobab::getDescription() {

    return description;
};

double Baobab::calculateCost() {
    return basePrice;
};

Baobab::~Baobab() {
    
};