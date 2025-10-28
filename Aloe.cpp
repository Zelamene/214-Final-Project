#include "Aloe.h"
#include <iostream>


Aloe::Aloe(double height)
    : Tree("Aloe", "Low Maintenance", height) { 
    std::cout << "🌿 Aloe planted.\n";
}

void Aloe::displayInfo() const {
    std::cout << "Aloe - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}