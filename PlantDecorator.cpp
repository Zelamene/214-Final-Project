#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(NurseryPlant * plant): plantToDec(plant)
{
};

PlantDecorator::~PlantDecorator()
{
    delete plantToDec;
};
