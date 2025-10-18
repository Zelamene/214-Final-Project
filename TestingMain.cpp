#include "HighMaintenancePlantFactory.h"
#include "LowMaintenancePlantFactory.h"
#include "CrateFactory.h"
#include <iostream>

int main()
{
    HighMaintenancePlantFactory highFactory;
    LowMaintenancePlantFactory lowFactory;
    CrateFactory crateFactory;

    FloweringPlant* rose = highFactory.createFloweringPlant();
    Tree* blossom = highFactory.createTree();

    FloweringPlant* easyFlower = lowFactory.createFloweringPlant();
    Tree* baobab = lowFactory.createTree();

    Container* crate = crateFactory.createContainer();

    delete rose;
    delete blossom;
    delete easyFlower;
    delete baobab;
    delete crate;

    return 0;
}
