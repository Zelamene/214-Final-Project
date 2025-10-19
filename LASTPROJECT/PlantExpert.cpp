#include "PlantExpert.h"
#include <iostream>

PlantExpert::PlantExpert(const std::string& name, NurseryMediator* med) 
    : Staff(name, "Plant Expert", med) {}

void PlantExpert::provideCareAdvice(const std::string& plantType) {
    send("is providing care advice for " + plantType);
}

void PlantExpert::diagnosePlantProblem(const std::string& symptoms) {
    send("is diagnosing plant problem: " + symptoms);
}

void PlantExpert::recommendPlants(const std::string& conditions) {
    send("is recommending plants suitable for " + conditions);
}

void PlantExpert::conductPlantWorkshop() {
    send("is conducting a plant care workshop for customers");
}

void PlantExpert::performDuty() {
    send("is performing expert duties - plant consultation and education");
}
