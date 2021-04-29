#include "FullListException.h"

const char* FullListException::what() const throw()
{
    return "[Exception]: The list is full\n\n";
}
