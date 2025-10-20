#include "Issue.h"

Issue::Issue(std :: string id, std::string description, bool solved) {
    this->id = id;
    this->description = description;
    this->solved = solved;
}

Issue::~Issue() {}

void Issue::setDescription(std::string description) {
    this->description = description;
}

void Issue::setSolved(bool solved) {
    this->solved = solved;
}

std :: string Issue::getId() {
    return this->id;
}

std::string Issue::getDescription() {
    return this->description;
}

bool Issue::getSolved() {
    return this->solved;
}
