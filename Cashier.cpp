#include "Cashier.h"
using namespace std;
Cashier::Cashier(Inventory *inventory, const string &name, Garden *garden)
    : Staff(inventory, name, new LowMaintenancePlantCare())
{
    this->garden = garden;
    // Cashiers handle simple plant care
}

void Cashier::processSale(const string &plantName, double amount)
{
    if (!paymentStrategy)
    {
        cout << "No payment method selected!\n";
        return;
    }

    cout << "Processing sale for " << plantName << " - Amount: $" << amount << "\n";

    if (paymentStrategy->processPayment(amount))
    {
        cout << "Payment successful using " << paymentStrategy->getMethodName() << "\n";
        // Remove plant from inventory, update records, etc.
    }
    else
    {
        cout << "Payment failed!\n";
    }
}

void Cashier::setPaymentStrategy(PaymentStrategy *strategy)
{
    paymentStrategy = (strategy);
}

string Cashier::getPaymentMethod() const
{
    return paymentStrategy ? paymentStrategy->getMethodName() : "No method set";
}

void Cashier::update(NurseryPlant *plant)
{
    cout << getName() << " notified: " << plant->getName()
         << " reached " << plant->getStateName() << ".\n";

    if (plant->getStateName() == "Mature")
    {
        if (garden && garden->hasPlant(plant))
        {
            NurseryPlant *harvested = garden->removePlant(plant);
            if (harvested)
            {
                inventory->addPlant(harvested->getName(), harvested);
                cout << getName()
                     << " added" << harvested->getName() << " to inventory.\n";
            }
        }
    }
}