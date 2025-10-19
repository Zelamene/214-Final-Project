#ifndef STAFF
#define STAFF
#include <string>
#include <vector>
#include "Command.h";
#include "NurseryPlant.h";
#include "CareStrategy.h";

class Staff {
private:
    std :: string name;
    CareStrategy* strategy;
public:
    Staff(std :: string n, CareStrategy* s = nullptr)
        : name(n), strategy(s) {}

    std :: string getName() const { return name; }

    void setStrategy(CareStrategy* s) { strategy = s; }

   void Staff::careForPlant(NurseryPlant& plant) {
    std :: cout << name << " is caring for " << plant.getName() << "...\n";
    plant.addStaff(this);
    if (strategy)
        strategy->performCare(plant);
    else
        std :: cout << "No care strategy set for " << name << "!\n";
}

void perform(Command* cmd) {
        std :: cout  << name << " executing command...\n";
        cmd->execute();
    }

};

#endif