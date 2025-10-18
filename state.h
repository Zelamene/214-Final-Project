#ifndef STATE_H
#define STATE_H
#include <string>
class State{
    public:
        virtual ~State() = default;
        virtual void handleAction() = 0;
        virtual std::string getStateName() const = 0;
};

#endif