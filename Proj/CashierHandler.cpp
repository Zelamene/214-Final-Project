#include "CashierHandler.h"
#include "DisputeHandler.h"
#include "Issue.h"

#include <iostream>



void CashierHandler :: handle(Issue* issue)
{
    
    if(issue->getId() == "Cashier"){
        std::cout << "The cashier is handling the ticket... "  << std::endl;
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
CashierHandler :: CashierHandler()
{
    next = nullptr;
}



CashierHandler :: ~CashierHandler() 
{
    
}