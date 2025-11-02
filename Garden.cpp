#include "Garden.h"

Garden::~Garden()
{
}

void Garden::addPlant(NurseryPlant *plant, Container *container)
{
    if (plant)
    {
        plants.push_back({plant, container});
        cout << "Plant added to the garden: " << plant->getName();
        if (container)
            cout << " in a " << container->getType();
        cout << endl;
    }
}

NurseryPlant *Garden::removePlant(NurseryPlant *plant)
{
    auto it = std::find_if(plants.begin(), plants.end(),
                           [plant](const PlantEntry &entry)
                           {
                               return entry.plant == plant;
                           });

    if (it != plants.end())
    {
        NurseryPlant *harvested = it->plant;
        delete it->container;
        plants.erase(it);
        return harvested;
    }
    return nullptr;
}

void Garden::displayPlants() const
{
    if (plants.empty())
    {
        cout << "The garden is empty." << endl;
        return;
    }

    cout << "Plants in the garden:" << endl;
    for (size_t i = 0; i < plants.size(); ++i)
    {
        cout << i << ": ";
        if (plants[i].plant && plants[i].container)
        {
            plants[i].plant->displayInfo();
            plants[i].container->display();
        }
        else if (plants[i].plant)
        {
            plants[i].plant->displayInfo();
            cout << " [Container missing]" << endl;
        }
        else
        {
            cout << " [Plant removed/invalid]" << endl;
        }
    }
}
int Garden::getPlantCount() const
{
    return plants.size();
}
