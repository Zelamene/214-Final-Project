/**
 * @file Baobab.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Baobab tree.
 */

#ifndef BAOBAB_H
#define BAOBAB_H

#include "Tree.h"
#include <string>

/**
 * @class Baobab
 * @brief Represents a Baobab tree, known for its massive trunk.
 */
class Baobab : public Tree
{

public:
    /**
     * @brief Constructs a Baobab with a given age.
     * 
     */
    Baobab();

    /**
     * @brief Destructor.
     */
    ~Baobab() {}
};

#endif // BAOBAB_H
