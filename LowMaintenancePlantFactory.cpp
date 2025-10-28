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

    double price;
    std::cout << "Enter price of a Flowering Plant : ";
    std::cin >> price;

    return new Rose(color, price);
}

Tree* LowMaintenancePlantFactory::createTree() {
    std::cout << "Creating a low maintenance tree (Aloe)" << std::endl;

    double height;
    std::cout << "Enter height of Aloe (in meters): ";
    std::cin >> height;

    double price;
    std::cout << "Enter price of a tree : ";
    std::cin >> price;

    return new Aloe(height, price);
}