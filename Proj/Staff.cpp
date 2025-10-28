#include "Staff.h"  

Staff::Staff(std::string n, CareStrategy* s) : name(n), strategy(s) {

}

std :: string Staff::getName() {
    return name;
}

void Staff::setStrategy(CareStrategy* s) {
    strategy = s;
}

void Staff::careForPlant(NurseryPlant& plant)
     {
        std::cout << name << " is caring for " << plant.getName() << "...\n";
        plant.addStaff(this);
        if (strategy)
            strategy->performCare(plant);
        else
            std::cout << "No care strategy set for " << name << "!\n";
    }

void Staff::perform(Command* cmd) {
    std::cout << name << " executing command...\n";
    cmd->execute();
}

Staff :: ~Staff() {
    strategy = nullptr;
}
