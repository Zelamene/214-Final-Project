#ifndef BAOBABCARE_H
#define BAOBABCARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Baobab tree care
 * 
 * Implements the specific care routine for Baobab trees including
 * specialized watering, sunlight, and fertilization requirements.
 */
class BaobabCare : public CareStrategy {
public:
    /**
     * @brief Perform Baobab-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant& plant) override {
        std::cout << " Special care for Baobab\n";
        std::cout << "- Water: once every 2 weeks\n";
        std::cout << "- Sunlight: full exposure\n";
        std::cout << "- Fertilizer: once every 3 months\n";
        plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std::cout << "- Baobab state updated to: " << plant.getState() << "\n\n";
    }
};

#endif