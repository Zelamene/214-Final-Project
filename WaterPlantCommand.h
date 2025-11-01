/**
 * @file WaterPlantCommand.h
 * @brief Defines the WaterPlantCommand class for watering a plant.
 */

#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H

#include "Command.h"
#include "NurseryPlant.h"
using namespace std;

/**
 * @class WaterPlantCommand
 * @brief Command to water a specific plant.
 */
class WaterPlantCommand : public Command
{
private:
    string plantName; /// Name of the plant to be watered

public:
    /**
     * @brief Constructs the command with the name of the plant.
     * @param p Name of the plant
     */
    WaterPlantCommand(string p);

    /**
     * @brief Executes the watering action.
     */
    void execute() override;
};

#endif
