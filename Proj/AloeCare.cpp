#include "AloeCare.h"

void AloeCare::performCare(NurseryPlant& plant){
        std::cout << "Performing care for Aloe\n";
        std::cout << "- Water: once every 10 days (avoid overwatering)\n";
        std::cout << "- Sunlight: indirect light preferred\n";
        std::cout << "- Fertilizer: every 2 months\n";
       plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Aloe state updated to: " << plant.getState() << "\n\n";
    }