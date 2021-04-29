#include "OutOfIndexException.h"

const char* OutOfIndexException::what() const throw()
{
    return "[Exception]: Out of index!!!\n\n";
}
