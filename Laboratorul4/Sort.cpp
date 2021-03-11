#define _CRT_SECURE_NO_WARNINGS
#define rep(index1, n) for(int index1 = 0 ; index1 < (n); ++index1)

#include"Sort.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<cstdarg>
#include<string.h>


int convertNumber(char* number)
{
	int myNumber, lenString;
	lenString = strlen(number);
	myNumber = 0;


	for (int index = lenString - 1, powrr = 1; index >= 0; --index) {

		if (number[index] == '\0')
			continue;

		if (!(number[index] >= '0' && number[index] <= '9')) {
			printf("Wrong input!!! %c \n", number[index]);
			return 0;
		}

		myNumber += powrr * (number[index] - '0');
		powrr *= 10;
	}
	return myNumber;
}

Sort::Sort(int numberOfElements, int minimumValue, int maximumValue)
{
	this->numberOfElements = numberOfElements;
	this->myArray = (int*)malloc(numberOfElements * sizeof(int));
	time_t t;

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	for (int index1 = 0; index1 < numberOfElements; ++index1)
		this->myArray[index1] = minimumValue + rand() % (maximumValue - minimumValue + 1);

}
Sort::Sort(): myArray(new int[6] {1, 33, 9, 4, 5, 7})
{
	this->numberOfElements = 6;
}
Sort::Sort(int* arrayA, int numberOfElements)
{
	this->numberOfElements = numberOfElements;
	this->myArray = (int*)malloc(numberOfElements * sizeof(int));
	for (int index1 = 0; index1 < numberOfElements; ++index1)
		this->myArray[index1] = arrayA[index1];
}
Sort::Sort(int count,...)
{
	this->numberOfElements = count;
	this->myArray = (int*)malloc(count * sizeof(int));

	va_list pargs;
	va_start(pargs, count);

	rep(index1, count)
	{
		this->myArray[index1] = va_arg(pargs, int);
	}
	va_end(pargs);
}
Sort::Sort(char* arrayA)
{
	this->numberOfElements = 0;
	char* pch;
	pch = strtok(arrayA, ",");
	while (pch != nullptr)
	{
		this->myArray = (int*)realloc(this->myArray, (this->numberOfElements + 1) * sizeof(int));
		this->myArray[this->numberOfElements] = convertNumber(pch);
		this->numberOfElements++;
		pch = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent)
{
	int key, index2;
	int type = 1;

	if (ascendent == false)
	{
		type *= -1;
	}

	for (int index1 = 1; index1 < this->numberOfElements; ++index1)
	{
		key = this->myArray[index1];
		
		index2 = index1 - 1;

		while (index2 >= 0 && type * this->myArray[index2] > type * key)
		{
			myArray[index2 + 1] = myArray[index2];
			--index2;
		}
		myArray[index2 + 1] = key;

	}
}

int Sort::partition(int low, int high, int type)
{
	int aux;
	int pivot = this->myArray[high];
	int index = (low - 1);
	for (int index2 = low; index2 <= high - 1; ++index2) {
		if (type * this->myArray[index2] < type * pivot)
		{
			++index;
			aux = this->myArray[index];
			this->myArray[index] = this->myArray[index2];
			this->myArray[index2] = aux;
		}
	}
	aux = this->myArray[index + 1];
	this->myArray[index + 1] = this->myArray[high];
	this->myArray[high] = aux;
	return index + 1;
}

void Sort::theRealQuickSort(int low, int high, int type)
{
	if (low < high)
	{
		int parti = partition(low, high, type);

		theRealQuickSort(low, parti - 1, type);
		theRealQuickSort(parti + 1, high, type);
	}
}

void Sort::QuickSort(bool ascendent)
{
	int type = 1;

	if (ascendent == false)
	{
		type *= -1;
	}
	
	theRealQuickSort(0, this->numberOfElements - 1, type);

}

void Sort::BubbleSort(bool ascendent)
{
	int aux;
	bool isSorted = false;
	int type = 1;

	if (ascendent == false)
	{
		type *= -1;
	}

	for (int index1 = 0; index1 < this->numberOfElements - 1 && isSorted == false; ++index1)
	{
		for (int index2 = 0; index2 < this->numberOfElements - index1 - 1; ++index2)
		{
			if (type * this->myArray[index2] > type * this->myArray[index2 + 1]) 
			{
				aux = this->myArray[index2];
				this->myArray[index2] = this->myArray[index2 + 1];
				this->myArray[index2 + 1] = aux;
				isSorted = false;
			}
		}
	}
}

void Sort::Print()
{
	printf("Vectorul sortat este:\n");
	rep(index1, this->numberOfElements)
	{
		printf("%d ", this->myArray[index1]);
	}
	printf("\n");
	rep(index1, 40)
	{
		printf("=");
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->numberOfElements;
}

int Sort::GetElementFromIndex(int index)
{
	if (0 <= index && index < this->numberOfElements)
	{
		return this->myArray[index];
	}
	return -1;
}
