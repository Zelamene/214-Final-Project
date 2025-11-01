#include "Crate.h"
#include <iostream>
using namespace std;
Crate::Crate(const string& material)
    : material(material)
{
    cout << "Crate created with material: " << material << endl;
}

void Crate::display() const {
    cout << "Container type: Crate, Material: " << material << endl;
}

string Crate::getType() const {
    return "Crate";
}
