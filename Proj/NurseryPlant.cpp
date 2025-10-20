#include "NurseryPlant.h"

NurseryPlant::NurseryPlant(std::string n, double p) : name(n), state("new"), price(p) {

};

NurseryPlant::~NurseryPlant() {

};

std::string NurseryPlant::getName() {
    return name;
}

double NurseryPlant::getPrice() {
    return price;
}


std::string NurseryPlant::getState() {
    return state;
}






void NurseryPlant::addStaff(Staff* s) {
    staffList.push_back(s);
}


void NurseryPlant::showStaff() const {
    std::cout << "Staff caring for " << name << ": ";
    for (auto s : staffList)
        std::cout << s->getName() << " ";
    std::cout << "\n";
}

void NurseryPlant::prepare() {
    std::cout << name << " is being prepared...\n";
}

void NurseryPlant::setPrice(double p)
{
    this->price = p;

}

void NurseryPlant::setState(std::string s)
{
    this->state = s;
}

