#include "Rose.h"
#include <iostream>

Rose::Rose(const string& color, double price) : FloweringPlant("Rose","High Maintenance",color, price){
      cout << "🌹 A " << color << " Rose has been planted.\n";
}

void Rose::displayInfo() const {
    cout << "Rose (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
    cout << "🌹 Special care instructions for Rose applied.\n";
}