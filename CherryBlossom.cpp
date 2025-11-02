
#include "CherryBlossom.h"
#include <iostream>
using namespace std;

CherryBlossom::CherryBlossom(double price)
    : FloweringPlant("Cherry Blossom", "High Maintenance", "Pink", price) {
    cout << "🌸 Cherry Blossom planted.\n";
} //Assumption: I assumed all CherryBlossoms are pink

void CherryBlossom::displayInfo() const {
    cout << "Cherry Blossom (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
}
