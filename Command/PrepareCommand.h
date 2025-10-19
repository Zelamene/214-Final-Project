#ifndef PREPARECOMMAND_H
#define PREPARECOMMAND_H
#include "Command.h"
#include "NurseryPlant.h"
class PrepareCommand : public Command
{
public:
    PrepareCommand(NurseryPlant& plant) : plant(plant) {}
    void execute() override { plant.prepare(); }
private:
    NurseryPlant& plant;
};

#endif