#include "DeliverOrderCommand.h"

DeliverOrderCommand::DeliverOrderCommand(Order* o) : order(o) {}

void DeliverOrderCommand::execute() {
        cout << "Delivering order #" << order->getID()
                  << " to " << order->getCustomer()->getName() << "\n";
        order->setOrderStatus("delivered");
    }

