#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
class NurseryPlant;
class Staff : public Observer {

    public:
        Staff()=default;
        ~Staff()=default;
        void update(NurseryPlant* plant) override;
        std::string getName() const;
};


#endif
