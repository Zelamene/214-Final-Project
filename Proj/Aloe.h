#ifndef Aloe_H
#define Aloe_H

#include "NurseryPlant.h"
#include <string>

/**
 * @class Aloe
 * @brief Represents an Aloe Vera plant in the nursery system
 * 
 * This class implements the NurseryPlant interface for Aloe Vera plants,
 * providing specific descriptions and pricing for this plant type.
 */
class Aloe : public NurseryPlant {
    
public:
    /**
     * @brief Default constructor for Aloe plant
     */
    Aloe();
    
    /**
     * @brief Gets the description of the Aloe plant
     * @return String describing the Aloe plant
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Aloe plant
     * @return The price of the Aloe plant as a double
     */
    virtual double calculateCost() override;
    
    /**
     * @brief Virtual destructor for Aloe plant
     */
    virtual ~Aloe();
};

#endif // Aloe_H