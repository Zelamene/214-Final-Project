#include "NurseryPlant.h"
#include <iostream>
using namespace std;

NurseryPlant::NurseryPlant(const string &name, const string &maintenanceType, double price)
    : Order(price), name(name), maintenanceType(maintenanceType) {}

NurseryPlant::~NurseryPlant() {}

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
         << ", Maintenance Type: " << maintenanceType
         << ", Price: " << price << endl;
}
