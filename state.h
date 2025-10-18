#ifndef STATE_H
#define STATE_H
#include <string>

class NurseryPlant;
class State{
    public:
        virtual ~State() = default;
        virtual void handleAction(NurseryPlant* NurseryPlant) = 0;
        virtual std::string getStateName() const = 0;
};

#endif