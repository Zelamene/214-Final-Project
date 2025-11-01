#include "CommunicatingParticipant.h"
#include "NurseryMediator.h"
#include <iostream>

CommunicatingParticipant::CommunicatingParticipant(const std::string &name, NurseryMediator *mediator)
    : name(name), mediator(mediator) {}

void CommunicatingParticipant::setMediator(NurseryMediator *mediator)
{
    this->mediator = mediator;
}

void CommunicatingParticipant::send(const std::string &event)
{
    std::cout << "[" << name << "] sends: " << event << std::endl;
    if (mediator)
    {
        mediator->notify(this, event);
    }
}

void CommunicatingParticipant::receive(const std::string &message)
{
    std::cout << "[" << name << "] received: " << message << std::endl;
}

std::string CommunicatingParticipant::getName() const
{
    return name;
}