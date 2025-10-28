#include "Baobab.h"
#include <iostream>

Baobab::Baobab(double height)
    : Tree("Baobab", "High Maintenance", height ){
    std::cout << "🌳 Baobab planted.\n";
}

void Baobab::displayInfo() const {
    std::cout << "Baobab - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}