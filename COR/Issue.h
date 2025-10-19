#ifndef ISSUE_H
#define ISSUE_H
#include <string>


class Issue
{
public:
   Issue(std::string id,std::string description , bool solved);
  ~Issue();
   std :: string getId();
   std::string getDescription();
   bool getSolved();
   void setDescription(std::string description);
   void setSolved(bool solved);

  private:
   std :: string id;
   std::string description;
   bool solved;
   
};


#endif