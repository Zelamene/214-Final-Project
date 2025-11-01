#include "CrateFactory.h"
#include "Crate.h"
#include <iostream>
using namespace std;
Container* CrateFactory::createContainer(string material){
    
   
    return new Crate(material);
}