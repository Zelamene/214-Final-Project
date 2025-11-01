
#include "Staff.h"
#include "NurseryPlant.h"
#include "Inventory.h"
#include <iostream>

Staff::Staff(Inventory *inventory, std::string n, CareStrategy *s)
    : CommunicatingParticipant(n, nullptr), inventory(inventory), strategy(s)
{
}

Staff::~Staff()
{
    delete strategy;
}
void Staff::setStrategy(CareStrategy *s)
{
    if (strategy)
    {
        delete strategy;
    }
    strategy = s;
}

string Staff::getName() const
{
    return name;
}
void Staff::careForPlant(NurseryPlant &plant)
{
    cout << name << " is caring for " << plant.getName() << "...\n";
    plant.attach(this);
    if (strategy)
        strategy->performCare(plant);
    else
        cout << "No care strategy set for " << name << "!\n";
}
void Staff::perform(Command *cmd)
{
    cout << name << " executing command...\n";
    cmd->execute();
}