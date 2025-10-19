#include "BowDecorator.h"

BowDecorator::BowDecorator(NurseryPlant* plant) : PlantDecorator(plant){};

std::string BowDecorator::getDescription(){
    return plantToDec->getDescription() + " in a Bow";
};

double BowDecorator::calculateCost(){
    double total = plantToDec->calculateCost() + 50.0;
    return total;
}