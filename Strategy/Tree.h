#ifndef TREE_H
#define TREE_H
#include "NurseryPlant.h"
#include <string>

class Tree : public NurseryPlant {
   public:
Tree(std::string n, double p) : NurseryPlant(n, p) {}
    std::string getType() const override { return "Tree"; }
};

#endif