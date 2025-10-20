#include "RoseCare.h"

void RoseCare:: performCare(NurseryPlant& plant) {
        std::cout << "Performing care for Rose\n";
        std::cout << "- Water: daily (lightly)\n";
        std::cout << "- Sunlight: 5–6 hours/day\n";
        std::cout << "- Fertilizer: rose mix every 10 days\n";
       plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Rose state updated to: " << plant.getState() << "\n\n";
    }