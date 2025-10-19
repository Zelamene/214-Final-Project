#ifndef BAOBABCARE_H
#define BAOBABCARE_H
#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>
class BaobabCare : public CareStrategy {
public:
    void performCare(NurseryPlant& plant) override {
        std :: cout << " Special care for Baobab\n";
        std :: cout << "- Water: once every 2 weeks\n";
        std :: cout << "- Sunlight: full exposure\n";
        std :: cout << "- Fertilizer: once every 3 months\n";
        plant.setState(plant.getState() == "seed" ? "sprouting" : "mature");
        std :: cout << "- Baobab state updated to: " << plant.getState() << "\n\n";
    }
};
#endif