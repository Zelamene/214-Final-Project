#include "GiftWrap.h"

GiftWrap::GiftWrap(NurseryPlant* plant) : PlantDecorator(plant){};

std::string GiftWrap::getDescription(){
    return plantToDec->getDescription() + " with Gift Wrap";
};

double GiftWrap::calculateCost(){
    double total = plantToDec->calculateCost() + 15.0;
    return total;
}