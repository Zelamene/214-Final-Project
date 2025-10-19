
#ifndef ROSECARE_H
#define ROSECARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Rose plant care
 * 
 * Implements the specific care routine for Rose plants including
 * frequent watering, sunlight requirements, and specialized fertilizer.
 */
class RoseCare : public CareStrategy {
public:
    /**
     * @brief Perform Rose-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant& plant) override {
        std::cout << "Performing care for Rose\n";
        std::cout << "- Water: daily (lightly)\n";
        std::cout << "- Sunlight: 5–6 hours/day\n";
        std::cout << "- Fertilizer: rose mix every 10 days\n";
       plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Rose state updated to: " << plant.getState() << "\n\n";
    }
};

#endif