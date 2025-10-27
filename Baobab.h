#ifndef Baobab_H
#define Baobab_H

#include "NurseryPlant.h"
#include <string>

/**
 * @class Baobab
 * @brief Represents a Baobab Tree in the nursery system
 * 
 * This class implements the NurseryPlant interface for Baobab trees,
 * providing specific descriptions and pricing for this large tree species.
 */
class Baobab : public NurseryPlant {
    
public:
    /**
     * @brief Default constructor for Baobab tree
     */
    Baobab();
    
    /**
     * @brief Gets the description of the Baobab tree
     * @return String describing the Baobab tree
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Baobab tree
     * @return The price of the Baobab tree as a double
     */
    virtual double calculateCost() override;
    
    /**
     * @brief Virtual destructor for Baobab tree
     */
    virtual ~Baobab();
};

#endif // Baobab_H