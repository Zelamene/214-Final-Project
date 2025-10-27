#ifndef BowDecorator_H
#define BowDecorator_H

#include "PlantDecorator.h"
#include <string>

/**
 * @class BowDecorator
 * @brief Decorator that adds a decorative bow to a plant
 * 
 * This class implements the Decorator pattern to add bow decoration
 * functionality to any NurseryPlant, modifying its description and cost.
 */
class BowDecorator : public PlantDecorator {

public:
    /**
     * @brief Constructor that wraps a plant with bow decoration
     * @param plant Pointer to the plant being decorated
     */
    BowDecorator(NurseryPlant* plant);
    
    /**
     * @brief Gets the description of the plant with bow decoration
     * @return String describing the decorated plant
     */
    std::string getDescription() override;
    
    /**
     * @brief Calculates the total cost including bow decoration
     * @return The total price as a double
     */
    double calculateCost() override;
};

#endif // BowDecorator_H