#include "Rose.h"
#include <iostream>

Rose::Rose(const std::string& color) : FloweringPlant("Rose","High Maintenance",color){
      std::cout << "🌹 A " << color << " Rose has been planted.\n";
}

void Rose::displayInfo() const {
    std::cout << "Rose (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
}