#include "BowDecorator.h"
using namespace std;
BowDecorator::BowDecorator(NurseryPlant *plant) : PlantDecorator(plant) {};

string BowDecorator::getDescription()
{
    if (plantToDec)
    {
        return plantToDec->getName() + " 🎀";
    }
    else
    {
        exit(1);
    }
};

double BowDecorator::calculateCost()
{
    double total = plantToDec->getTotal() + 50.0;
    return total;
}