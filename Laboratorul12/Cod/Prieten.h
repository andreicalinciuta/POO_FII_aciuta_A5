#ifndef _PRIETEN_H
#define _PRIETEN_H


#include "Contact.h"
#include <string>
using namespace std;

class Prieten : public Contact {
  private:
    string dataNasterii;
    string numarTelefon;
    string adresa;
public:
    Prieten();
    Prieten(string, string, string, string);

};
#endif
