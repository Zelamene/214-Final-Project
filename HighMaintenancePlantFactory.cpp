#include "HighMaintenancePlantFactory.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include "Aloe.h"
#include "Baobab.h"
#include <iostream>

FloweringPlant* HighMaintenancePlantFactory::createFloweringPlant(){
    std::cout << "Creating a high maintenance flowing plant (CherryBlossom)" << std::endl;
    return new CherryBlossom();
}

Tree* HighMaintenancePlantFactory::createTree() {
    std::cout << "Creating a high maintenance tree (Baobab)" << std::endl;
    return new Baobab();
}