#ifndef FLOWERINGPLANT_H
#define FLOWERINGPLANT_H

#include "NurseryPlant.h"
#include <string>

/**
 * @brief Concrete class representing a Flowering Plant type
 * 
 * This class implements the Flowering Plant category, inheriting from NurseryPlant
 * and providing specific flowering plant functionality.
 */
class FloweringPlant : public NurseryPlant {
public:
    /**
     * @brief Construct a new Flowering Plant object
     * @param n Name of the flowering plant
     * @param p Price of the flowering plant
     */
    FloweringPlant(std::string n, double p) : NurseryPlant(n, p) {}
    
    /**
     * @brief Get the type of plant
     * @return std::string Always returns "Flowering Plant"
     */
    std::string getType() const override { return "Flowering Plant"; }
};

#endif