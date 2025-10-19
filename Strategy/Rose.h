#ifndef ROSE_H
#define ROSE_H
#include "NurseryPlant.h"
#include "FloweringPlant.h"
#include <string>

class Rose : public FloweringPlant {
private:
   
public:
    Rose(double price = 25.0) : FloweringPlant("Rose", price){
        setState("seed"); 
    }
};

#endif