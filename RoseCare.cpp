#include "RoseCare.h"
#include "ConcreteState.h"
void RoseCare::performCare(NurseryPlant &plant)
{
    cout << "Performing care for Rose\n";
    cout << "- Water: daily (lightly)\n";
    cout << "- Sunlight: 5–6 hours/day\n";
    cout << "- Fertilizer: rose mix every 10 days\n";

    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }

    cout << "- Rose state updated to: " << plant.getStateName() << "\n\n";
}