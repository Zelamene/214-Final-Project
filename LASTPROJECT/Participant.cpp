#include "Participant.h"
#include "NurseryMediator.h"
#include <iostream>

Participant::Participant(const std::string& name, NurseryMediator* med) 
    : name(name), mediator(med) {}

Participant::~Participant() {}

void Participant::setMediator(NurseryMediator* med) {
    mediator = med;
}

void Participant::receive(const std::string& message) {
    std::cout << "[" << name << "] received: " << message << std::endl;
}

void Participant::send(const std::string& event) {
    std::cout << "[" << name << "] sends: " << event << std::endl;
    if (mediator) {
        mediator->notify(this, event);
    }
}

std::string Participant::getName() const {
    return name;
}