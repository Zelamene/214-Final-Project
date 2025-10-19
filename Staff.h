#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
#include "State.h"
class Staff : public Observer {

    public:
        Staff()=default;
        ~Staff()=default;
        void update(State state) override;
        std::string getName() const;
};


#endif