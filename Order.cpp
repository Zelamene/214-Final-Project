#include "Order.h"
#include <iomanip>

Order::Order(double price)
{
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm tm = *localtime(&now);

    ostringstream ss;
    ss << "ORD-" << put_time(&tm, "%Y%m%d-%H%M%S")
       << "-" << (random_device{}() % 9000 + 1000);

    this->orderID = ss.str();
    this->price = price;
}

Order::Order(){
    
}

Order::~Order()
{
}

string Order::getID()
{
    return orderID;
}
