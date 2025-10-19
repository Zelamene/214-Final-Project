#ifndef CHERRYBLOSSOM_H
#define CHERRYBLOSSOM_H
#include "NurseryPlant.h"
#include "FloweringPlant.h"
#include <string>

class CherryBlossom : public FloweringPlant {
private:
  
public:
    CherryBlossom(double price = 40.0) : FloweringPlant("CherryBlossom", price){
        setState("seed"); 
    }
};

#endif