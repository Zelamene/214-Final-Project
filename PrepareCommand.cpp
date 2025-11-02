#include "PrepareCommand.h"
#include "NurseryPlant.h"

PrepareCommand ::PrepareCommand(Order *order)
{
    this->order = order;
}

void PrepareCommand::execute()
{
    cout << "🛒 Adding order #" << order->getID() << " to shopping cart\n";
    order->setOrderStatus("prepared");
}
