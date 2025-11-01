#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H

#include <string>
using namespace std;

/**
 * @class MessageReceiver
 * @brief Interface for objects that can receive messages.
 *
 * Classes implementing this interface can receive messages from
 * MessageSender objects or a mediator.
 */
class MessageReceiver
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~MessageReceiver() = default;

    /**
     * @brief Receives a message.
     * @param message The message being received.
     */
    virtual void receive(const std::string &message) = 0;
};

#endif