#ifndef _CONTACT_H
#define _CONTACT_H


#include <string>
using namespace std;
#include "contactType.h"

class Contact {
    string nume;
    contactType myContactType;
  public:
    contactType getType();
    void setName(string);
    string getName();

};
#endif
