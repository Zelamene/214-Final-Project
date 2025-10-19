#ifndef ALOE_H
#define ALOE_H
#include "NurseryPlant.h"
#include "Tree.h"
#include <string>

class Aloe : public Tree {
private:
    
public:
    Aloe(double price = 35.0) : Tree("Aloe", price){
        setState("seed"); 
    }
};

#endif