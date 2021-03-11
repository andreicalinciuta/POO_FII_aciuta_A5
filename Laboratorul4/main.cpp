#include"Sort.h"
#include <stdio.h>

int main()
{
	Sort test1(10, 4, 3324);
	test1.InsertSort(true);
	test1.Print();

	Sort test2;
	test2.InsertSort();
	test2.Print();

	int arrayTest[] = { 32, 5435, 3, 66, 7 };
	Sort test3(arrayTest, 5);
	test3.BubbleSort(false);
	test3.Print();

	Sort test4(6,3,9,5,3,6,4);
	test4.BubbleSort(true);
	test4.Print();

	char cList[] = "21,32,9,4,10";
	Sort test5(cList);
	test5.QuickSort(true);
	test5.Print();

	printf("\nUltimul vector are %d elemente, iar elementul de pe pozitia 3 este: %d\n", test5.GetElementsCount(), test5.GetElementFromIndex(2));

	return 0;
}