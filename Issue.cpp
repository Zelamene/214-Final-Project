#include "Issue.h"

Issue::Issue(string id, string description, Order *order, bool solved)
{
    this->id = id;
    this->description = description;
    this->solved = solved;
    this->relatedOrder = order;
}

Issue::~Issue() {}

void Issue::setDescription(string description)
{
    this->description = description;
}

void Issue::setSolved(bool solved)
{
    this->solved = solved;
}

std ::string Issue::getID()
{
    return this->id;
}

string Issue::getDescription()
{
    return this->description;
}

bool Issue::getSolved()
{
    return this->solved;
}