
#ifndef ALOE_H
#define ALOE_H

#include "NurseryPlant.h"
#include "Tree.h"
#include <string>

/**
 * @brief Concrete class representing an Aloe plant
 * 
 * Aloe is a specific type of Tree .
 * 
 */
class Aloe : public Tree {
private:
             

public:
    /**
     * @brief Construct a new Aloe object
     * @param price Initial price, defaults to 35.0
     */
    
    Aloe(double price = 35.0);
};

#endif