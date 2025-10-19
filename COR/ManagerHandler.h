#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H
#include "Issue.h"
#include "DisputeHandler.h"
#include <string>


class ManagerHandler : public DisputeHandler 
{
public:
    ManagerHandler();
    
    virtual ~ManagerHandler();
  
   
   void handle(Issue* issue);
    

   
private:
    
  
   
};

#endif