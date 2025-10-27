#include <iostream>
#include <algorithm>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include <thread>
#include <chrono>

using namespace std;

NurseryPlant::NurseryPlant(const string &name, const string &maintenanceType, double price)
    : Order(price), name(name), maintenanceType(maintenanceType),waterlevel(100) {
    this-> currentState=new SeedlingState();

    }

NurseryPlant::~NurseryPlant() {
     delete currentState;
}

string NurseryPlant::getName() const
{
    return name;
}

string NurseryPlant::getMaintenanceType() const
{
    return maintenanceType;
}

double NurseryPlant::getTotal()
{
    return price + (price * taxRate);
}

void NurseryPlant::setWaterlevel(int number){

    this->waterlevel=number;
    return;

}

void NurseryPlant::displayDetails()
{
    cout << "Nursery Plant Order: " << orderID
         << " | Name: " << name
         << " | Maintenance Type: " << maintenanceType
         << " | Base Price: " << price
         << " | Total (with tax): " << getTotal() << endl;
}

void NurseryPlant::calculateTax()
{
    cout << "Tax for " << orderID << ": " << price * taxRate << endl;
}

Order *NurseryPlant::clone() const
{
    return new NurseryPlant(*this);
}

void NurseryPlant::displayInfo() const
{
    cout << "Plant Name: " << name
        <<"Plant State: " << getStateName()
         << ", Maintenance Type: " << maintenanceType
         << ", Price: " << price << endl;
}

void NurseryPlant::setState(State* newState) {
    delete currentState;
    currentState = newState;
    notify();
}

void NurseryPlant::startGrowing() {
    while (this->getStateName() != "Mature") {
        std::this_thread::sleep_for(std::chrono::seconds(1));
         waterlevel-(rand() % 40)<0?waterlevel=0:waterlevel-=rand() % 40;
        currentState->handleAction(this);
        if(waterlevel>=70){
            cout<<GREEN<<planCurrentState()<<RESET<<endl;
        }else if(waterlevel>=30){
            cout<<YELLOW<<planCurrentState()<<RESET<<endl;
        }else{
            cout<<RED<<planCurrentState()<<RESET<<endl;
            pourWater(60);
            cout<<RED<<"emegence water supply added 60 mililiters of water"<<RESET<<endl;

        }
    }
}

int NurseryPlant::getWaterLevel(){
    return waterlevel;
}

void NurseryPlant::pourWater(int liters){

        this->waterlevel+liters;
    
    
}

// rand() % 10
std::string NurseryPlant::planCurrentState() const {
    std::string status;
    
    if(waterlevel>=70){
       status="Plant: "+this->getName()+" Water level :"+to_string(waterlevel)+" State: "+this->getStateName()+"Status: Healthy";
    }else if(waterlevel>=30){
        status="Plant: "+this->getName()+" Water level :"+to_string(waterlevel)+" State: "+this->getStateName()+"Status: Needs Watering";
        
    }else{
        status="Plant: "+this->getName()+" Water level :"+to_string(waterlevel)+" State: "+this->getStateName()+"Status: Critical - Immediate Watering Required";
        
    }
    return status;
   
}



std::string NurseryPlant::getStateName() const {
    return currentState->getStateName();
}

void NurseryPlant::attach(Observer* observer) {
    observers.push_back(observer);
}

void NurseryPlant::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void NurseryPlant::notify() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}
