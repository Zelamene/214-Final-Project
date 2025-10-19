#ifndef NURSERYPLANT_H
#define NURSERYPLANT_H
#include <string>
#include <vector>
#include "Staff.h"
class NurseryPlant {
protected:
    std :: string name;
    std :: string state;
    double price;
    std :: vector<Staff*> staffList;

public:
    NurseryPlant(std :: string n, double p)
        : name(n), state("new"), price(p) {}

    virtual ~NurseryPlant() = default;

    std :: string getName() 
    { 
        return name; 

    }
    double getPrice()  { 
        return price; 
    }

    void setPrice(double p) { 
        
        price = p; 
    }

    void setState(std :: string s) { 
        state = s; 
    }
    std :: string getState() const { 
        return state; 
    }

    void addStaff(Staff* s) { 
        staffList.push_back(s); 
    }

    void showStaff() const {
        std :: cout << "Staff caring for " << name << ": ";
        for (auto s : staffList)
            std ::cout << s->getName() << " ";
        std :: cout << "\n";
    }

    void prepare() { std :: cout << name << " is being prepared...\n"; }

    virtual std :: string getType() const = 0;
};

#endif