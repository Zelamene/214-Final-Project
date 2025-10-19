#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std :: string name;
public:
    Customer(std :: string n) : name(n) {}
    std :: string getName() const { return name; }
};

#endif;