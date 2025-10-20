#include "DisputeHandler.h"
#include <iostream>

DisputeHandler::DisputeHandler()
{
    next = nullptr;
}

void DisputeHandler::setNext(DisputeHandler* myNext)
{
    this->next = myNext;
}

void DisputeHandler::handle(Issue* issue)
{
    if (next != nullptr)
    {
        std::cout << "The issue is being passed to the next handler... " << std::endl;
        next->handle(issue);
    }
    else
    {
        std::cout << "Issue Unhandled" << std::endl;
    }
}

DisputeHandler::~DisputeHandler()
{
    delete next;
}
