#include <iostream>
#include "NurseryPlant.h"
#include "BulkOrder.h"
#include "OrderSlip.h"
#include "RefundSlip.h"
using namespace std;

int main()
{
    cout << "=== Testing Composite Pattern (BulkOrder + NurseryPlant) ===" << endl;

    Order *plant1 = new NurseryPlant("PlantName", "LowMaintenance", 100.0);
    Order *plant2 = new NurseryPlant("PlantName", "HighMaintenance", 150.0);
    Order *plant3 = new NurseryPlant("pn", "HighMaintenance", 200.0);

    BulkOrder *bulk = new BulkOrder();
    bulk->addOrder(plant1);
    bulk->addOrder(plant2);
    bulk->addOrder(plant3);

    cout << "-- Single Plant Order --" << endl;
    plant1->displayDetails();

    cout << "\n-- Bulk Order Details --" << endl;
    bulk->displayDetails();

    // Calculate tax for all leaf order
    plant1->calculateTax();

    // Calculate tax for all orders
    cout << "\nCalculating taxes for bulk order..." << endl;
    bulk->calculateTax();

    // === Testing Iterator Pattern ===
    cout << "\n=== Testing Iterator Pattern ===" << endl;
    Iterator *it = bulk->createIterator();
    while (it->hasNext())
    {
        Order *o = it->next();
        o->displayDetails();
    }

    // calling next when iteration is finished
    try
    {
        it->next();
    }
    catch (const out_of_range &e)
    {
        cout << "After finishing exception: " << e.what() << endl;
    }
    delete it;

    // empty BulkOrder iteration
    BulkOrder *emptyBulk = new BulkOrder();
    Iterator *emptyIt = emptyBulk->createIterator();
    cout << "\nIterating over empty bulk order:" << endl;
    if (!emptyIt->hasNext())
        cout << "No orders to iterate." << endl;
    delete emptyIt;
    delete emptyBulk;

    // === Testing Prototype Pattern ===
    cout << "\n=== Testing Prototype Pattern (For Cloning BulkOrder) ===" << endl;
    Order *clonedBulk = bulk->clone();
    cout << "Original Bulk Order:" << endl;
    bulk->displayDetails();

    cout << "\nCloned Bulk Order:" << endl;
    clonedBulk->displayDetails();

    // === Testing Template Method Pattern ===
    cout << "\n=== Testing Template Method Pattern (OrderSlip and  RefundSlip) ===" << endl;
    OrderSlip orderSlip(bulk);
    RefundSlip refundSlip(plant2);

    cout << "\n-- Printing Order Slip --" << endl;
    orderSlip.printSlip();

    cout << "\n-- Printing Refund Slip --" << endl;
    refundSlip.printSlip();

    delete bulk;
    delete clonedBulk;

    cout << "\n===Tests complete, no leaks ===" << endl;
    return 0;
}
