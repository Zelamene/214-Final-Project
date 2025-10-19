
#ifndef BAOBAB_H
#define BAOBAB_H

#include "NurseryPlant.h"
#include "Tree.h"
#include <string>

/**
 * @brief Concrete class representing a Baobab tree
 * 
 * Baobab is a specific type of Tree
 * 
 */
class Baobab : public Tree {
private:
            

public:
    /**
     * @brief Construct a new Baobab object
     * @param price Initial price, defaults to 120.0
     */
    Baobab(double price = 120.0) : Tree("Baobab", price){
        setState("seed"); 
    }
};

#endif