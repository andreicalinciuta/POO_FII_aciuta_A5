#ifndef _COLEG_H
#define _COLEG_H


#include <string>
using namespace std;
#include "Contact.h"

class Coleg : public Contact {
  private:
    string numarTelefon;

    string firma;

    string adresa;
public:
    Coleg();
    Coleg(string, string, string, string);


};
#endif
