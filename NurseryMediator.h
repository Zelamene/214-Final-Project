#ifndef NurseryMediator_H
#define NurseryMediator_H

#include <string>
#include "CommunicatingParticipant.h"
using namespace std;


/**
 * @class NurseryMediator
 * @brief Abstract interface for the nursery mediator
 * 
 * This abstract class defines the interface for all concrete mediators
 * in the plant nursery system, following the Mediator pattern.
 */
class NurseryMediator {
public:

    
    /**
     * @brief Pure virtual method for handling communication between participants
     * @param sender The participant sending the message
     * @param event The message/event being sent
     */
    virtual void notify(MessageSender * sender, const string& event) = 0;
    
    /**
     * @brief Virtual destructor for proper polymorphism
     */
    virtual ~NurseryMediator();
};

#endif // NurseryMediator_H