#include "BaobabCare.h"

void BaobabCare::performCare(NurseryPlant& plant) {
        std::cout << " Special care for Baobab\n";
        std::cout << "- Water: once every 2 weeks\n";
        std::cout << "- Sunlight: full exposure\n";
        std::cout << "- Fertilizer: once every 3 months\n";
        plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Baobab state updated to: " << plant.getState() << "\n\n";
    }