#include "Garden.h"

Garden::~Garden()
{

    plants.clear();
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

void Garden::removePlant(int index)
{
    if (index < 0 || index >= plants.size())
    {
        cout << "Invalid index. Cannot remove plant." << endl;
        return;
    }

    delete plants[index].plant;
    delete plants[index].container;
    plants.erase(plants.begin() + index);
    cout << "Plant removed from the garden." << endl;
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
        plants[i].plant->displayInfo();
        if (plants[i].container)
        {
            plants[i].container->display();
        }
    }
}

int Garden::getPlantCount() const
{
    return plants.size();
}
