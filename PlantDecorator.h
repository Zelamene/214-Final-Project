#ifndef PlantDecorator_H
#define PlantDecorator_H

#include "NurseryPlant.h"
#include <string>
using namespace std;

/**
 * @class PlantDecorator
 * @brief Abstract base class for all plant decorators
 *
 * This class implements the base functionality for the Decorator pattern,
 * allowing dynamic addition of features to NurseryPlant objects.
 */
class PlantDecorator : public NurseryPlant
{

protected:
    NurseryPlant *plantToDec; /// Pointer to the plant being decorated

public:
    /**
     * @brief Constructor for PlantDecorator
     * @param plant Pointer to the plant to be decorated
     */
    PlantDecorator(NurseryPlant *plant);

    /**
     * @brief Pure virtual method to get decorated plant description
     * @return String describing the decorated plant
     */
    virtual string getDescription() = 0;

    /**
     * @brief Pure virtual method to calculate decorated plant cost
     * @return The total price including decorations
     */
    virtual double calculateCost() = 0;

    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~PlantDecorator();
};

#endif // PlantDecorator_H