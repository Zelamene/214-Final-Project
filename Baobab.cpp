#include "Baobab.h"
#include <iostream>
using namespace std;
Baobab::Baobab(double height, double price)
    : Tree("Baobab", "High Maintenance", height, price)
{
    cout << "🌳 Baobab planted.\n";
}

void Baobab::displayInfo() const
{
    cout << "Baobab - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}