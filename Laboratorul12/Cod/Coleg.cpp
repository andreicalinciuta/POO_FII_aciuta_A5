
#include "Coleg.h"

Coleg::Coleg()
{

}
Coleg::Coleg(string nume, string numarTelefon, string firma, string adresa)
{
	this->numarTelefon = numarTelefon;
	this->nume = nume;
	this->firma = firma;
	this->adresa = adresa;
	this->myContactType = Coleg;
}
