#include<iostream>

#include"Agenda.h"

using namespace std;

int main()
{
	Agenda myAgenda;

	Prieten Jeff;
	Jeff.setName("Jeff Cine Altcineva");
	myAgenda.adaugaContact(Jeff);
	string nume = "Jeff";
	myAgenda.cautaContact(nume);

	string nume2 = "Jeff Cine Altcineva";
	myAgenda.cautaContact(nume2);

	myAgenda.stergeContact("Jeff Cine Altcineva");

}