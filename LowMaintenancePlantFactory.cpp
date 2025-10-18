#include "LowMaintenancePlantFactory.h"
#include "Aloe.h"
#include "Baobab.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include <iostream>

FloweringPlant* LowMaintenancePlantFactory::createFloweringPlant(){
    std::cout << "Creating a low maintenance flowing plant (Rose)" << std::endl;
    return new Rose();
}

Tree* LowMaintenancePlantFactory::createTree() {
    std::cout << "Creating a high maintenance tree (Aloe)" << std::endl;
    return new Aloe();
}