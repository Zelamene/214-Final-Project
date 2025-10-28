#include "ManagerHandler.h"
#include "ManagerHandler.h"
#include "Issue.h"

#include <iostream>



void ManagerHandler :: handle(Issue* issue)
{
    
    if(issue->getId() == "Manager"){
        std::cout << "The manager is handling the ticket... "  << std::endl;
        issue->setSolved(true);
       
    }
    else{
        if(next){
            std::cout << "The issue is being passed to the next handler... "  << std::endl;
            //this->setNext(this->next);
            next->handle(issue);
        }
        else{
            std::cout << "Dispute Unhandled" << std::endl;
        }
    }
    
}
ManagerHandler :: ManagerHandler ()
{
    next = nullptr;
}



ManagerHandler  :: ~ManagerHandler () 
{
    
}