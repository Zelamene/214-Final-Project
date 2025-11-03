#ifndef GiftWrap_H
#define GiftWrap_H

#include "PlantDecorator.h"
#include <string>
using namespace std;

/**
 * @class GiftWrap
 * @brief Decorator that adds gift wrapping to a plant
 *
 * This class implements the Decorator pattern to add gift wrapping
 * functionality to any NurseryPlant, modifying its description and cost.
 */
class GiftWrap : public PlantDecorator
{

public:
    /**
     * @brief Constructor that wraps a plant with gift wrapping
     * @param plant Pointer to the plant being decorated
     */
    GiftWrap(NurseryPlant *plant);

    /**
     * @brief Gets the description of the plant with gift wrapping
     * @return String describing the gift-wrapped plant
     */
    string getDescription() override;

    /**
     * @brief Calculates the total cost including gift wrapping
     * @return The total price as a double
     */
    double calculateCost() override;
};

#endif // GiftWrap_H