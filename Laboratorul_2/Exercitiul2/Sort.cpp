#include "Sort.h"
#include <string.h>

int SortByName(Student* x, Student* y)
{
	return strcmp(x->getName(), y->getName());
}

int SortByMath(Student* x, Student* y)
{
	if (x->getMathGrade() == y->getMathGrade())
	{
		return 0;
	}
	else if (x->getMathGrade() > y->getMathGrade())
	{
		return 1;
	}
	else
		return -1;
}

int SortByHistory(Student* x, Student* y)
{
	if (x->getHistoryGrade() == y->getHistoryGrade())
	{
		return 0;
	}
	else if (x->getHistoryGrade() > y->getHistoryGrade())
	{
		return 1;
	}
	else
		return -1;
}

int SortByEnglish(Student* x, Student* y)
{
	if (x->getEnglishGrade() == y->getEnglishGrade())
	{
		return 0;
	}
	else if (x->getEnglishGrade() > y->getEnglishGrade())
	{
		return 1;
	}
	else
		return -1;
}

int SortByAverage(Student* x, Student* y)
{
	if (x->getAverageGrade() == y->getAverageGrade())
	{
		return 0;
	}
	else if (x->getAverageGrade() > y->getAverageGrade())
	{
		return 1;
	}
	else
		return -1;
}
