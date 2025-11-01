#include "FloweringPlant.h"
FloweringPlant::FloweringPlant(const string& name, const string& maintenanceType, const string& color, double price)
        : NurseryPlant(name, maintenanceType, price), color(color) {}
string FloweringPlant::getColor() const {
    return color;
}
