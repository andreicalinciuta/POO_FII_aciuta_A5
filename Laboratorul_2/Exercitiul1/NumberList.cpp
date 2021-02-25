#include "NumberList.h"
#include<iostream>

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		return false;
	}
	this->numbers[this->count] = x;
	this->count += 1;
	return true;
}
void NumberList::Sort()
{
	for(int index1 = 0 ; index1 < this->count ; ++index1)
		for(int index2 = index1 + 1 ; index2 < this->count ; ++index2)
			if (this->numbers[index1] > this->numbers[index2])
			{
				
				this->numbers[index1] ^= this->numbers[index2] ^= this->numbers[index1] ^= this->numbers[index2];
			}
}
void NumberList::Print()
{
	for (int index1 = 0; index1 < this->count; ++index1)
	{
		printf("%d ", this->numbers[index1]);
	}
	printf("\n");
}
