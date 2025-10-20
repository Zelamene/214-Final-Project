#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include <vector>
#include <string>
#include <iostream>
#include "NurseryPlant.h"

/**
 * @brief Strategy interface for plant care behaviors
 * 
 * This class defines the interface for implementing different care strategies
 * for various types of plants using the Strategy design pattern.
 */
class NurseryPlant;
class CareStrategy {
public:
    /**
     * @brief Perform care routine for a specific plant
     * @param plant Reference to the NurseryPlant to care for
     */
    virtual void performCare(NurseryPlant& plant);
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~CareStrategy();
};

#endif