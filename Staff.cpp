#include "Staff.h"
#include "NurseryPlant.h"
#include "Inventory.h"
#include <iostream>
#include <map>


Staff::Staff(Inventory* inventory) : inventory(inventory) {
}

Staff::~Staff(){
    
}

void Staff::update(NurseryPlant* plant) {
    std::cout << "Staff notified: Plant '" << plant->getStateName() << "' state changed.\n" << std::endl;

    enum PlantStats{
        Seeding,
        Sprout,
        Mature,
        Wilting
    };
    
    int addWater=(rand() % 100);
    if(addWater<20){
        int waterToAdd=(rand()%20);
        plant->pourWater(waterToAdd);
        std::cout<<"Staff add: "<<to_string(waterToAdd)<<"\n"<<endl;
    }

    if(plant->getWaterLevel()<30){
        plant->pourWater(60);
    }

    if (plant->getStateName() == "Seeding") {
        std::cout << "Plnted a new seed" << std::endl;

    }

    if (plant->getStateName() == "Sprout") {
        std::cout << "Plant still growing add water" << std::endl;
        
    }


    if (plant->getStateName() == "Mature") {
        inventory->addPlant(plant->getName(), plant);
        std::cout << "Staff added plant to inventory." << std::endl;
    }

    if (plant->getStateName() == "Wilting") {
        std::cout << "Plant died create a new plant" << std::endl;
        
    }
}

std::string Staff::getName() const {
    return "Staff Member";
}
