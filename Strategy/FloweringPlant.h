#ifndef FLOWERINGPLANT_H
#define FLOWERINGPLANT_H
#include "NurseryPlant.h"
#include <string>

class FloweringPlant : public NurseryPlant {
   public:
    FloweringPlant(std::string n, double p) : NurseryPlant(n, p) {}
    std::string getType() const override { return "Flowering Plant"; }
};

#endif