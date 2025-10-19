#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
#include "Inventory.h"
class NurseryPlant;
class Staff : public Observer {
    private:
    Inventory* inventory;
        

    public:
        Staff(Inventory* inventory);
        ~Staff()=default;
        void update(NurseryPlant* plant) override;
        std::string getName() const;
};


#endif
