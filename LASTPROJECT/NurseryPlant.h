#ifndef NURSERY_H
#define NURSERY_H

#include <string>

/**
 * @class NurseryPlant
 * @brief Abstract base class for all plants in the nursery system
 * 
 * This class defines the interface for all plant types in the nursery,
 * following the Decorator pattern for plant customization.
 */
class NurseryPlant {
protected:
    std::string description;  ///< Description of the plant
    double basePrice;         ///< Base price of the plant without decorations
    
public:
    /**
     * @brief Gets the description of the plant
     * @return String describing the plant
     */
    virtual std::string getDescription() = 0;
    
    /**
     * @brief Calculates the cost of the plant
     * @return The price of the plant as a double
     */
    virtual double calculateCost() = 0;
    
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~NurseryPlant();
};

#endif // NURSERY_H