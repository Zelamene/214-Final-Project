#include "CherryCare.h"

void CherryBlossomCare:: performCare(NurseryPlant& plant) {
        std::cout << "Performing care for Cherry Blossom\n";
        std::cout << "- Water: every 3 days\n";
        std::cout << "- Sunlight: bright but partial shade\n";
        std::cout << "- Fertilizer: early spring & mid-summer\n";
        plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Cherry Blossom state updated to: " << plant.getState() << "\n\n";
    }