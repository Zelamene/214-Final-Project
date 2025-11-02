#include "GiftWrap.h"

GiftWrap::GiftWrap(NurseryPlant *plant) : PlantDecorator(plant) {};

string GiftWrap::getDescription()
{
    return plantToDec->getName() + " 🎁 with Gift Wrap";
    ;
};

double GiftWrap::calculateCost()
{
    double total = plantToDec->getTotal() + 15.0;
    return total;
}