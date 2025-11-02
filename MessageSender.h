#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <string>
using namespace std;

class NurseryMediator;

/**
 * @class MessageSender
 * @brief Interface for objects that can send messages via a mediator.
 *
 * Classes implementing this interface can send messages/events
 * and set a mediator to coordinate communication.
 */
class MessageSender
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~MessageSender() = default;

    /**
     * @brief Sends a message/event.
     * @param event The message or event to send.
     */
    virtual void send(const std::string &event) = 0;

    /**
     * @brief Sets the mediator for sending messages.
     * @param mediator Pointer to the NurseryMediator.
     */
    virtual void setMediator(NurseryMediator *mediator) = 0;
};

#endif