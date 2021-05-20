#ifndef _CUNOSCUT_H
#define _CUNOSCUT_H


#include "Contact.h"
#include <string>
using namespace std;

class Cunoscut : public Contact {
  private:
    string numarTelefon;
public:
    Cunoscut();
    Cunoscut(string);
};
#endif
