#include "CherryCare.h"
#include "ConcreteState.h"
using namespace std;
void CherryBlossomCare::performCare(NurseryPlant &plant)
{
    cout << "Performing care for Cherry Blossom\n";
    cout << "- Water: every 3 days\n";
    cout << "- Sunlight: bright but partial shade\n";
    cout << "- Fertilizer: early spring & mid-summer\n";
    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }
    cout << "- Cherry Blossom state updated to: " << plant.getStateName() << "\n\n";
}