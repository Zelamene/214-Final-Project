#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H
#include "Command.h"
#include "NurseryPlant.h"
class WaterPlantCommand : public Command {
private:
    std :: string plantName;
public:
    WaterPlantCommand(std :: string p) : plantName(p) {}
    void execute() override {
        std :: cout << "Watering plant: " << plantName << "\n";
    }
};

#endif