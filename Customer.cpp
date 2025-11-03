#include "Customer.h"
#include <iostream>
Customer::Customer(string n, NurseryMediator *mediator) : CommunicatingParticipant(n, mediator)
{
    name = n;
}

string Customer::getName()
{
    return name;
}

void Customer::browsePlants()
{
    cout << name << " is browsing the available plants...\n";
    if (mediator)
        mediator->notify(this, name + " is browsing the sales floor.");
}

void Customer::requestAdvice(const std::string &plantType)
{
    cout << name << ": 'Could I get some advice on caring for " << plantType << " plants?'\n";
    if (mediator)
        mediator->notify(this, name + " wants information about " + plantType);
    else
        cout << "⚠️ No mediator available — cannot forward request.\n";
}

void Customer::purchasePlant(const std::string &plantName)
{
    cout << name << ": 'I'd like to buy a " << plantName << " please.'\n";
    if (mediator)
        mediator->notify(this, name + " wants to purchase " + plantName);
    else
        cout << "⚠️ No mediator available — cannot process purchase.\n";
}
