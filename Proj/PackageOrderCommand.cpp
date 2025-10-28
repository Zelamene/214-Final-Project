#include "PackageOrderCommand.h"

PackageOrderCommand::PackageOrderCommand(Order* o) : order(o) {}

void PackageOrderCommand::execute()  {
        std::cout << "Packaging order #" << order->getId()
                  << " (" << order->getPlantName() << ")\n";
        order->setState("packaged");
    }
