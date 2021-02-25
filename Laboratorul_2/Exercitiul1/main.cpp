#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList v;
	v.Init();
	for (int index = 0; index <= 10; ++index)
	{
		int number = (index + 64) * (index + 2) % (index + 3);
		if (v.Add(number))
		{
			printf("S-a adaugat cu succes numarul: %d \n", number);
		}
		else {
			printf("In lista sunt deja 10 elemente\n");
		}
	}
	v.Sort();
	v.Print();
	return 0;
}