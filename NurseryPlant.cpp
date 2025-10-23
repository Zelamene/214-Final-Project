

/**
 * @file NurseryPlant.cpp
 * @brief Implementation of the NurseryPlant class.
 */
#include <iostream>
#include <algorithm>
#include "NurseryPlant.h"
#include "ConcreteState.h"

using namespace std;

NurseryPlant::NurseryPlant(const string &name, const string &maintenanceType, double price)
    : Order(price), name(name), maintenanceType(maintenanceType) {
    this-> currentState=new SeedlingState();

    }


/**
 * @brief Destructor for NurseryPlant.
 */
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

/**
 * @brief Sets a new state for the plant and notifies observers.
 * @param newState Pointer to the new state object.
 */
void NurseryPlant::setState(State* newState) {
    delete currentState;
    currentState = newState;
    notify();
}

/**
 * @brief Gets the name of the plant.
 * @return The name of the plant as a string.
 */

/**
 * @brief Starts the growing process by transitioning through states until mature.
 */
void NurseryPlant::startGrowing() {
    while (this->getStateName() != "Mature") {
        currentState->handleAction(this);
    }
}

/**
 * @brief Gets the name of the current state.
 * @return The name of the current state as a string.
 */
std::string NurseryPlant::getStateName() const {
    return currentState->getStateName();
}

/**
 * @brief Attaches an observer to this plant.
 * @param observer Pointer to the observer to attach.
 */
void NurseryPlant::attach(Observer* observer) {
    observers.push_back(observer);
}

/**
 * @brief Detaches an observer from this plant.
 * @param observer Pointer to the observer to detach.
 */
void NurseryPlant::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

/**
 * @brief Notifies all attached observers of a state change.
 */
void NurseryPlant::notify() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}
