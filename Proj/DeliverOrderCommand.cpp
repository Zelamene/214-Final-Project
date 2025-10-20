#include "DeliverOrderCommand.h"

DeliverOrderCommand::DeliverOrderCommand(Order* o) : order(o) {}

void DeliverOrderCommand::execute() {
        std::cout << "Delivering order #" << order->getId()
                  << " to " << order->getCustomer()->getName() << "\n";
        order->setState("delivered");
    }

