
#include "CherryBlossom.h"
#include <iostream>


CherryBlossom::CherryBlossom()
    : FloweringPlant("Cherry Blossom", "High Maintenance", "Pink") {
    std::cout << "🌸 Cherry Blossom planted.\n";
} //Assumption: I assummed all CherryBlossoms are pink

void CherryBlossom::displayInfo() const {
    std::cout << "Cherry Blossom (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
}
