#include "DisputeHandler.h"
#include <iostream>

DisputeHandler::DisputeHandler()
{
    next = nullptr;
}

void DisputeHandler::setNext(DisputeHandler *myNext)
{
    this->next = myNext;
}

void DisputeHandler::handle(Issue *issue)
{
    if (canHandle(issue))
    {
        processIssue(issue);
        issue->setSolved(true);
    }
    else if (next)
    {
        next->handle(issue);
    }
    else
    {
        cout << "No handler available for issue: "
                  << issue->getID() << endl;
    }
}

DisputeHandler::~DisputeHandler()
{
    // delete next;
}
