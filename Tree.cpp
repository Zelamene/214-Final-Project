#include "Tree.h"

Tree::Tree(const std::string& name, const std::string& maintenanceType, double height)
        : NurseryPlant(name, maintenanceType), height(height) {}
double Tree::getHeight() const {
    return height;
}