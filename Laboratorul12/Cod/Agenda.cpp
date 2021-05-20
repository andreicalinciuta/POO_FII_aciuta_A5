
#include "Agenda.h"
#include "Contact.h"

bool Agenda::cautaContact(string nume) {
	for (auto it : contacteAgenda)
		if ((*it).getName() == nume)
			return true;
	return false;
}

vector<Contact*> Agenda::prieteni() {
	vector<Contact*>sol;
	for (auto it : contacteAgenda)
		if ((*it).getType() == Prieten)
			sol.push_back(it);
	return sol;
}

bool Agenda::stergeContact(string nume) {
	for (vector<Contact*>::iterator it = sol.begin(); it != sol.end(); ++it)
		if ((*it).getName == nume)
			sol.erase(it);
}

bool Agenda::adaugaContact(Contact contact) {
	Contact* contactNou = new Contact();
	*contactNou = contact;
	contacteAgenda.push_back(contactNou);
}

