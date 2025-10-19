#ifndef DISPUTEHANDLER_H
#define DISPUTEHANDLER_H

#include "DisputeHandler.h"
#include "Issue.h"

class DisputeHandler
{
public:
   DisputeHandler();
  virtual ~DisputeHandler();
   void setNext(DisputeHandler* next);
   virtual void handle(Issue* issue);

   protected:
   DisputeHandler* next;
   
};


#endif
