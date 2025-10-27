#ifndef CherryBlossom_H
#define CherryBlossom_H

#include "NurseryPlant.h"
#include <string>

/**
 * @class CherryBlossom
 * @brief Represents a Cherry Blossom tree in the nursery system
 * 
 * This class implements the NurseryPlant interface for Cherry Blossom trees,
 * providing specific descriptions and pricing for this ornamental tree species.
 */
class CherryBlossom : public NurseryPlant {
    
public:
    /**
     * @brief Default constructor for Cherry Blossom tree
     */
    CherryBlossom();
    
    /**
     * @brief Gets the description of the Cherry Blossom tree
     * @return String describing the Cherry Blossom tree
     */
    virtual std::string getDescription() override;
    
    /**
     * @brief Calculates the cost of the Cherry Blossom tree
     * @return The price of the Cherry Blossom tree as a double
     */
    virtual double calculateCost() override;
    
    /**
     * @brief Virtual destructor for Cherry Blossom tree
     */
    virtual ~CherryBlossom();
};

#endif // CherryBlossom_H