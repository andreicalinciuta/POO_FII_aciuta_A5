#pragma once
#include "Compare.h"
class Greater:public Compare
{
	int CompareElements(void* e1, void* e2) final;
};

