#include "Nurse.h"
#include <iostream>

Nurse::Nurse(const std::string& name, NurseryMediator* med) 
    : Staff(name, "Plant Nurse", med) {}

void Nurse::waterPlants() {
    send("is watering plants according to their specific needs");
}

void Nurse::fertilizePlants() {
    send("is applying fertilizer to plants that need nutrients");
}

void Nurse::prunePlants() {
    send("is pruning plants for healthy growth and appearance");
}

void Nurse::monitorPlantHealth() {
    send("is monitoring plant health and checking for issues");
}

void Nurse::treatSickPlant(const std::string& plantName, const std::string& issue) {
    send("is treating " + plantName + " for issue: " + issue);
}

void Nurse::performDuty() {
    send("is performing nursing duties - plant health care and maintenance");
}
