#ifndef ROSE_H
#define ROSE_H

#include "NurseryPlant.h"
#include <string>

/**
 * @class Rose
 * @brief Represents a Rose plant in the nursery system
 * 
 * This class implements the NurseryPlant interface for Rose plants,
 * providing specific descriptions and pricing for this popular flower.
 */
class Rose : public NurseryPlant {
    
public:
    /**
     * @brief Default constructor for Rose plant
     */
    Rose();
    
    /**
     * @brief Gets the description of the Rose plant
     * @return String describing the Rose plant
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Rose plant
     * @return The price of the Rose plant as a double
     */
    virtual double calculateCost() override;
    
    /**
     * @brief Virtual destructor for Rose plant
     */
    virtual ~Rose();
};

#endif // ROSE_H