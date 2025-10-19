#ifndef CASHIERHANDLER_H
#define CASHIERHANDLER_H
#include "Issue.h"
#include "DisputeHandler.h"
#include <string>


class CashierHandler : public DisputeHandler 
{
public:
    CashierHandler();
    
    virtual ~CashierHandler();
  
   
   void handle(Issue* issue);
    

   
private:
    
  
   
};

#endif