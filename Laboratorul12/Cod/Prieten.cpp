
#include "Prieten.h"
Prieten::Prieten() {

}
Prieten::Prieten(string dataNasterii, string nume, string numarTelefon, string adresa) {
    this->dataNasterii = dataNasterii;
    this->nume = nume;
    this->myContactType = Prieten;
    this->numarTelefon = numarTelefon;
    this->adresa = adresa;
}
