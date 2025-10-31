#include "Cashier.h"
using namespace std;
Cashier::Cashier(Inventory *inventory, const string &name)
    : Staff(inventory, name, new LowMaintenancePlantCare())
{
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
        cout << getName() << " adding " << plant->getName()
                  << " to inventory for sale.\n";
        inventory->addPlant(plant->getName(), plant);
    }
}