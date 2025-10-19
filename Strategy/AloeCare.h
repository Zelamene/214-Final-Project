#ifndef ALOECARE_H
#define ALOECARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Aloe plant care
 * 
 * Implements the specific care routine for Aloe plants including
 * watering schedule, sunlight requirements, and fertilization.
 */
class AloeCare : public CareStrategy {
public:
    /**
     * @brief Perform Aloe-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant& plant) override {
        std::cout << "Performing care for Aloe\n";
        std::cout << "- Water: once every 10 days (avoid overwatering)\n";
        std::cout << "- Sunlight: indirect light preferred\n";
        std::cout << "- Fertilizer: every 2 months\n";
       plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Aloe state updated to: " << plant.getState() << "\n\n";
    }
};

#endif