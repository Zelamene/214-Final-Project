#include "PackageOrderCommand.h"

PackageOrderCommand::PackageOrderCommand(Order *o) : order(o) {}

void PackageOrderCommand::execute()
{
    cout << "Packaging order #" << order->getID() << "\n";
    order->setOrderStatus("packaged");
}
