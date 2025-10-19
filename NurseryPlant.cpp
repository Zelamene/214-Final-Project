#include "NurseryPlant.h"
#include <iostream>
using namespace std;

NurseryPlant::NurseryPlant(double price)
    : Order(price) {}

NurseryPlant::~NurseryPlant()
{
}

double NurseryPlant::getTotal()
{
    return price + (price * taxRate);
}

void NurseryPlant::displayDetails()
{
    cout << "Nursery Plant Order: " << orderID
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
