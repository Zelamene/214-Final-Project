#ifndef TREE_H
#define TREE_H

#include "NurseryPlant.h"
#include <string>

/**
 * @brief Concrete class representing a Tree type plant
 * 
 * This class implements the Tree category of plants, inheriting from NurseryPlant
 * and providing specific tree-related functionality.
 */
class Tree : public NurseryPlant {
public:
    /**
     * @brief Construct a new Tree object
     * @param n Name of the tree
     * @param p Price of the tree
     */
    Tree(std::string n, double p);
    
    /**
     * @brief Get the type of plant
     * @return std::string Always returns "Tree"
     */
    std::string getType() const override { return "Tree"; }
};

#endif