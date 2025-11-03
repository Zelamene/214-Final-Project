#include "AloeCare.h"
#include "ConcreteState.h"
void AloeCare::performCare(NurseryPlant &plant)
{
    cout << "Performing care for Aloe\n";
    cout << "- Water: once every 10 days (avoid overwatering)\n";
    cout << "- Sunlight: indirect light preferred\n";
    cout << "- Fertilizer: every 2 months\n";

    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }

    cout << "- Aloe state updated to: " << plant.getStateName() << "\n\n";
}