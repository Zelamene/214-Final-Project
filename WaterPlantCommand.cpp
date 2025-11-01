#include "WaterPlantCommand.h"

WaterPlantCommand::WaterPlantCommand(string p)
{
    plantName = p;
}

void WaterPlantCommand::execute()
{
    cout << "Watering " << plantName << "...\n";
}
