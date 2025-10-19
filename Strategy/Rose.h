
#ifndef ROSE_H
#define ROSE_H

#include "NurseryPlant.h"
#include "FloweringPlant.h"
#include <string>

/**
 * @brief Concrete class representing a Rose plant
 * 
 * Rose is a specific type of Flowering Plant with its own
 * state management and care requirements.
 */
class Rose : public FloweringPlant {


public:
    /**
     * @brief Construct a new Rose object
     * @param price Initial price, defaults to 25.0
     */
    Rose(double price = 25.0) : FloweringPlant("Rose", price){
        setState("seed"); 
    }

    
};

#endif