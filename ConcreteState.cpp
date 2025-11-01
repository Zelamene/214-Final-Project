
#include "ConcreteState.h"
#include "NurseryPlant.h"
#include <iostream>
using namespace std;
void SeedlingState::handleAction(NurseryPlant *plant)
{
    cout << "The " << plant->getName() << " Planted\n";
    bool stillGrowing = (rand() % 100) < 50;
    if (stillGrowing)
    {
        cout << "The seedling is still growing. It needs more time.\n";
        return;
    }

    plant->setState(new SproutState());
}

string SeedlingState::getStateName() const
{
    return "Seedling";
}

void SproutState::handleAction(NurseryPlant *plant)
{
    cout << "The " << plant->getName() << " is a sprout. It is growing leaves and needs nutrients.\n";

    if (plant->getWaterLevel() <= 5)
    {
        cout << "Oh no! The sprout( " << plant->getName() << " ) died due to lack of water.\n";
        plant->setWaterlevel(100);
        plant->setState(new WiltingPlantState());
        return;
    }
    bool readyToMature = (rand() % 100) < 50;
    if (!readyToMature)
    {
        cout << "The sprout( " << plant->getName() << " ) is still developing. It needs more care.\n";
        return;
    }

    bool pestAttack = (rand() % 100) < 20;
    if (pestAttack)
    {
        cout << "Oh no! The sprout( " << plant->getName() << " ) was attacked by pests and is wilting.\n";
        plant->setState(new WiltingPlantState());
        return;
    }
    plant->setState(new MatureState());
}
string SproutState::getStateName() const
{
    return "Sprout";
}

void MatureState::handleAction(NurseryPlant *plant)
{
    cout << "The " << plant->getName() << " is mature. It is flowering and may need pruning.\n";
    plant->setState(new WiltingPlantState());
}
string MatureState::getStateName() const
{
    return "Mature";
}

void WiltingPlantState::handleAction(NurseryPlant *plant)
{
    cout << "The " << plant->getName() << " is wilting. It needs immediate care to recover.\n";
    plant->setState(new SeedlingState());
}

string WiltingPlantState::getStateName() const
{
    return "Wilting";
}
