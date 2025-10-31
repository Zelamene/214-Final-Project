
#include "CherryBlossom.h"
#include <iostream>


CherryBlossom::CherryBlossom(double price)
    : FloweringPlant("Cherry Blossom", "High Maintenance", "Pink", price) {
    std::cout << "🌸 Cherry Blossom planted.\n";
} //Assumption: I assumed all CherryBlossoms are pink

CherryBlossom::CherryBlossom(){
    description = "CherryBlossom";
    basePrice = 250.0;
};

void CherryBlossom::displayInfo() const {
    std::cout << "Cherry Blossom (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
}

std::string CherryBlossom::getDescription() {

    return description;
};

double CherryBlossom::calculateCost() {
    return basePrice;
};

CherryBlossom::~CherryBlossom() {
    
};
