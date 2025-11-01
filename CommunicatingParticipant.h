#ifndef COMMUNICATINGPARTICIPANT_H
#define COMMUNICATINGPARTICIPANT_H

#include "MessageSender.h"
#include "MessageReceiver.h"
#include <string>
using namespace std;

class NurseryMediator;

/**
 * @class CommunicatingParticipant
 * @brief Base class for participants that can send and receive messages via a mediator.
 */
class CommunicatingParticipant : public MessageSender, public MessageReceiver
{
protected:
    std::string name;          /** Participant's name */
    NurseryMediator *mediator; /** Mediator for communication */

public:
    /**
     * @brief Constructs a participant with a name and optional mediator.
     * @param name Participant's name.
     * @param mediator Mediator for communication (default nullptr).
     */
    CommunicatingParticipant(const std::string &name, NurseryMediator *mediator = nullptr);

    /**
     * @brief Default destructor.
     */
    virtual ~CommunicatingParticipant() = default;

    /**
     * @brief Sets the mediator for this participant.
     * @param mediator Mediator instance.
     */
    void setMediator(NurseryMediator *mediator) override;

    /**
     * @brief Sends a message/event through the mediator.
     * @param event Message/event to send.
     */
    void send(const std::string &event) override;

    // MessageReceiver interface
    /**
     * @brief Receives a message from the mediator.
     * @param message The received message.
     */
    void receive(const std::string &message) override;

    /**
     * @brief Gets the participant's name.
     * @return Name as a string.
     */
    std::string getName() const;
};

#endif