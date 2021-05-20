#ifndef _AGENDA_H
#define _AGENDA_H


#include <vector>
using namespace std;
#include <string>
using namespace std;

class Contact;

class Agenda {
  private:
    vector<Contact *> contacteAgenda;


  public:
    bool cautaContact(string nume);

    vector<Contact*> prieteni();

    bool stergeContact(string nume);

    bool adaugaContact(Contact contact);

};
#endif
