#include "Manager.h"
#include "Issue.h"
#include <iostream>

Manager::Manager(Inventory *inventory, const string &name)
    : Staff(inventory, name, new HighMaintenancePlantCare()) // Managers might handle complex cases
{
    staffMembers = {"Alice (Nurse)", "Bob (Cashier)", "Dr. Green (Expert)"};
}

void Manager::handleDispute(const string &customerName, const string &issue)
{
    cout << "Manager " << getName() << " handling dispute from " << customerName << endl;
    cout << "Issue: " << issue << endl;
    cout << " Dispute resolved by management authority.\n"
              << endl;
}

void Manager::reviewStaffPerformance()
{
    cout << "Manager " << getName() << " conducting staff performance review:" << endl;
    for (const auto &staff : staffMembers)
    {
        cout << " - Reviewing: " << staff << " - Performance: Satisfactory" << endl;
    }
    cout << " Performance review completed.\n"
              << endl;
}

void Manager::update(NurseryPlant *plant)
{
    cout << getName() << " overseeing: " << plant->getName()
              << " is now " << plant->getStateName() << ".\n";

    if (plant->getStateName() == "Mature")
    {
        cout << "Manager: verifying plant quality before it's added to inventory.\n";
        cout << "Quality check passed  — plant ready for sale approval.\n";
    }

    if (plant->getStateName() == "Wilting")
    {
        cout << "Manager: notifying Nurse to attempt recovery.\n";
    }
}