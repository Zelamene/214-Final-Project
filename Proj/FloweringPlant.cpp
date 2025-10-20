#include "FloweringPlant.h"

FloweringPlant::FloweringPlant(std::string n, double p) : NurseryPlant(n, p) {

}

std::string FloweringPlant::getType() const  {
    return "Flowering Plant";
}