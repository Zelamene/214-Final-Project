#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(NurseryPlant *plant) : NurseryPlant(plant->getName(), plant->getMaintenanceType(), plant->getTotal())
{
    this->plantToDec = plant;
}

PlantDecorator::~PlantDecorator()
{
 if (plantToDec) {
        delete plantToDec;
    }}
