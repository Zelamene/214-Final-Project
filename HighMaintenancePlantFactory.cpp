#include "HighMaintenancePlantFactory.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include "Aloe.h"
#include "Baobab.h"
#include <iostream>

FloweringPlant *HighMaintenancePlantFactory::createFloweringPlant(double price, string color)
{
    cout << "Creating a high maintenance flowing plant (CherryBlossom)" << endl;

    return new CherryBlossom(price);
}

Tree *HighMaintenancePlantFactory::createTree(double height, double price)
{
    cout << "Creating a high maintenance tree (Baobab)" << endl;

    return new Baobab(height, price);
}