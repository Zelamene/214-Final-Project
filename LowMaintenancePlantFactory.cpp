#include "LowMaintenancePlantFactory.h"
#include "Aloe.h"
#include "Baobab.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include <iostream>

FloweringPlant* LowMaintenancePlantFactory::createFloweringPlant(){
    std::cout << "Creating a low maintenance flowering plant (Rose)" << std::endl;

    std::string color;
    std::cout << "Enter color for your Rose (e.g., red, white, yellow): ";
    std::cin >> color;

    return new Rose(color);
}

Tree* LowMaintenancePlantFactory::createTree() {
    std::cout << "Creating a low maintenance tree (Aloe)" << std::endl;

    double height;
    std::cout << "Enter height of Aloe (in meters): ";
    std::cin >> height;

    return new Aloe(height);
}