

#include <iostream>
#include <algorithm>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include <thread>
#include <chrono>
#include "Staff.h"
using namespace std;

NurseryPlant::NurseryPlant(const string &name, const string &maintenanceType, double price)
    : Order(price), name(name), maintenanceType(maintenanceType)
{
    this->currentState = new SeedlingState();
}

NurseryPlant::~NurseryPlant()
{
    delete currentState;
}
string NurseryPlant::planCurrentState() const
{
    string status = "Plant: " + this->getName() +
                    " | Water: " + to_string(waterlevel) +
                    " | State: " + this->getStateName() +
                    " | Status: ";

    if (waterlevel >= 70)
        status += "Healthy";
    else if (waterlevel >= 30)
        status += "Needs Watering";
    else
        status += "Critical - Immediate Watering Required";

    return status;
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
    price = price + (price * taxRate);

    cout << "Tax for " << orderID << ": " << price << endl;
}

Order *NurseryPlant::clone() const
{
    return new NurseryPlant(*this);
}

void NurseryPlant::showStaff() const
{
    cout << "Staff caring for " << name << ": ";
    for (auto s : observers)
        cout << (dynamic_cast<Staff *>(s))->getName() << " ";
    cout << "\n";
}

void NurseryPlant::displayInfo() const
{
    cout << "Plant Name: " << name
         << "Plant State: " << getStateName()
         << ", Maintenance Type: " << maintenanceType
         << ", Price: " << price << endl;
}

void NurseryPlant::setState(State *newState)
{
    delete currentState;
    currentState = newState;
    notify();
}

void NurseryPlant::startGrowing()
{
    while (this->getStateName() != "Mature")
    {
        this_thread::sleep_for(chrono::seconds(1));
        int waterLoss = rand() % 10 + 5;
        waterlevel = (waterlevel - waterLoss) < 0 ? 0 : waterlevel - waterLoss;
        currentState->handleAction(this);
        if (waterlevel >= 70)
        {
            cout << GREEN << planCurrentState() << RESET << endl;
        }
        else if (waterlevel >= 30)
        {
            cout << YELLOW << planCurrentState() << RESET << endl;
        }
        else
        {
            cout << RED << planCurrentState() << RESET << endl;
            pourWater(60);
            cout << RED << "emegence water supply added 60 mililiters of water" << RESET << endl;
        }
    }
}

int NurseryPlant::getWaterLevel()
{
    return waterlevel;
}

void NurseryPlant::pourWater(int liters)
{
    this->waterlevel += liters;
}

void NurseryPlant::setWaterlevel(int number)
{

    this->waterlevel = number;
    return;
}

string NurseryPlant::getStateName() const
{
    return currentState->getStateName();
}

void NurseryPlant::attach(Observer *observer)
{
    observers.push_back(observer);
}

void NurseryPlant::detach(Observer *observer)
{
    auto it = find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
    {
        observers.erase(it);
    }
}

void NurseryPlant::notify()
{
    for (Observer *obs : observers)
    {
        obs->update(this);
    }
}