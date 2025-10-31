#ifndef Participant_H
#define Participant_H

#include <string>
#include "NurseryMediator.h"

/**
 * @class Participant
 * @brief Base class for all participants in the nursery mediator system
 * 
 * This class provides the common interface and functionality for all
 * participants (customers, staff, inventory) that communicate through the mediator.
 */
class Participant {
protected:
    NurseryMediator* mediator;  ///< Pointer to the mediator for communication
    std::string name;           ///< Name identifier for the participant

public:
    /**
     * @brief Constructor for Participant
     * @param name The name of the participant
     * @param med Pointer to the nursery mediator (optional)
     */
    Participant(const std::string& name, NurseryMediator* med = nullptr);
    
    /**
     * @brief Sets the mediator for this participant
     * @param med Pointer to the nursery mediator
     */
    void setMediator(NurseryMediator* med);
    
    /**
     * @brief Receives a message from the mediator
     * @param message The message received
     */
    virtual void receive(const std::string& message);
    
    /**
     * @brief Sends an event/message through the mediator
     * @param event The event/message to send
     */
    virtual void send(const std::string& event);
    
    /**
     * @brief Gets the name of the participant
     * @return The participant's name as string
     */
    std::string getName() const;
    
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Participant();
};

#endif // Participant_H