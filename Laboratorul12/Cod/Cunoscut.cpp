
#include "Cunoscut.h"

Cunoscut::Cunoscut() {

}
Cunoscut::Cunoscut(string numarTelefon, string nume) {
    this->nume = nume;
    this->myContactType = Cunoscut;
    this->numarTelefon = numarTelefon;
}
