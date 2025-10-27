#include "Staff.h"
#include <iostream>

Staff::Staff(const std::string& name, const std::string& role, NurseryMediator* med) 
    : Participant(name, med), role(role) {}

std::string Staff::getRole() const {
    return role;
}