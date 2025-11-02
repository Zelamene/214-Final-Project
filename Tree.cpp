#include "Tree.h"

Tree::Tree(const string &name, const string &maintenanceType, double height, double price)
    : NurseryPlant(name, maintenanceType, price), height(height) {}
double Tree::getHeight() const
{
    return height;
}
