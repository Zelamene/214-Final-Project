#include "HighMaintenancePlantFactory.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include "Aloe.h"
#include "Baobab.h"
#include <iostream>

FloweringPlant *HighMaintenancePlantFactory::createFloweringPlant()
{
    std::cout << "Creating a high maintenance flowing plant (CherryBlossom)" << std::endl;
    double price;
    std::cout << "Enter price of a Flowering Plant : ";
    std::cin >> price;

    return new CherryBlossom(price);
}

Tree *HighMaintenancePlantFactory::createTree()
{
    std::cout << "Creating a high maintenance tree (Baobab)" << std::endl;
    double height;
    std::cout << "Enter height of Baobab (in meters): ";
    std::cin >> height;
    double price;
    std::cout << "Enter price of a Baobab: ";
    std::cin >> price;
    return new Baobab(height, price);
}