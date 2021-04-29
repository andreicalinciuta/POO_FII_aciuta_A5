#include "Greater.h"

int Greater::CompareElements(void* e1, void* e2)
{
    return *((int*)e1) > *((int*)e2);
}
