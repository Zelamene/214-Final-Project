/**
 * @file PrepareCommand.h
 * @brief Command to prepare a nursery plant.
 */

#ifndef PREPARECOMMAND_H
#define PREPARECOMMAND_H

#include "Command.h"
#include "NurseryPlant.h"

/**
 * @class PrepareCommand
 * @brief Executes preparation of a nursery plant.
 */
class PrepareCommand : public Command {
public:
    /**
     * @brief Constructs the command with a plant reference.
     * @param plant Reference to the nursery plant
     */
    PrepareCommand(NurseryPlant& plant) : plant(plant) {}

    /**
     * @brief Executes the preparation.
     */
    void execute() override { plant.prepare(); }

private:
    NurseryPlant& plant; ///< Reference to the plant
};

#endif
