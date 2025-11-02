#include "BaobabCare.h"
#include "ConcreteState.h"
using namespace std;
void BaobabCare::performCare(NurseryPlant &plant)
{
    cout << " Special care for Baobab\n";
    cout << "- Water: once every 2 weeks\n";
    cout << "- Sunlight: full exposure\n";
    cout << "- Fertilizer: once every 3 months\n";
    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }
    cout << "- Baobab state updated to: " << plant.getStateName() << "\n\n";
}