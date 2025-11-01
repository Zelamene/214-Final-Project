#include "LowMaintenancePlantFactory.h"
#include "Aloe.h"
#include "Baobab.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include <iostream>

FloweringPlant *LowMaintenancePlantFactory::createFloweringPlant(double price, string color)
{
    cout << "Creating a low maintenance flowering plant (Rose)" << endl;

    return new Rose(color, price);
}

Tree *LowMaintenancePlantFactory::createTree(double height, double price)
{
    cout << "Creating a low maintenance tree (Aloe)" << endl;

    return new Aloe(height, price);
}