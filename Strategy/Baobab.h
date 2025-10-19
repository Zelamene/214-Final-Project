#ifndef BAOBAB_H
#define BAOBAB_H
#include "NurseryPlant.h"
#include "Tree.h"
#include <string>

class Baobab : public Tree {
private:
   
public:
    Baobab(double price = 120.0) : Tree("Baobab", price){
        setState("seed"); 
    }
};

#endif