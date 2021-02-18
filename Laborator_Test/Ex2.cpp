#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0) {
		printf("Nu se puede.\n");
	}
	else {
		printf("We are in!\n");

		int sum = 0, myNumber, lenString;
		bool test;
		char myFutureNumber[200];

		while (fgets(myFutureNumber, 199, fp)){

			lenString = strlen(myFutureNumber);
			myNumber = 0;

			if(myFutureNumber[lenString - 1] == '\n')
				myFutureNumber[lenString - 1] = '\0';
			printf("Am citit din fisier: %s\n", myFutureNumber);


			for (int index = lenString - 1, powrr = 1; index >= 0; --index) {

				if (myFutureNumber[index] == '\0')
					continue;

				if (!(myFutureNumber[index] >= '0' && myFutureNumber[index] <= '9')) {
					printf("Wrong input!!! %c \n", myFutureNumber[index]);
					return 0;
				}

				myNumber += powrr * (myFutureNumber[index] - '0');
				powrr *= 10;
			}

			sum += myNumber;
		}

		printf("The sum of your numbers is: %d\n", sum);

	}



	return 0;
}