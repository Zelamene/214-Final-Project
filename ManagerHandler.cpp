#include "ManagerHandler.h"
#include "ManagerHandler.h"
#include "Issue.h"

#include <iostream>

bool ManagerHandler::canHandle(Issue *issue)
{
    string id = issue->getID();
    return (id == "Manager" || id == "Escalated" || id == "Staff");
}

void ManagerHandler::processIssue(Issue *issue)
{
    cout << "ManagerHandler processing: "
              << issue->getDescription() << endl;

    string issueType = issue->getID();

    if (issueType == "Staff")
    {
        cout << "Addressing staff-related matter..." << endl;
        cout << "Scheduling performance review." << endl;
    }
    else if (issueType == "Escalated")
    {
        cout << "Reviewing escalated complaint..." << endl;
        cout << "Contacting customer directly." << endl;
    }
    else
    {
        cout << "Handling management decision..." << endl;
    }

    cout << "Manager issue resolved with authority.\n"
              << endl;
}
ManagerHandler ::ManagerHandler()
{
}

ManagerHandler ::~ManagerHandler()
{
}