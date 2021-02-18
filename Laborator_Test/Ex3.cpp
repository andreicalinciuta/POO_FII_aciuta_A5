#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	printf("Introduceti o propozitie care sa se termine cu caracterul '.': ");
	char cuvant[200][200];
	int numarCuvinte = 0;
	while (scanf_s("%199s", cuvant[numarCuvinte], 200)) {
		printf("Cuvantul citita este: %s\n", cuvant[numarCuvinte]);

		if (cuvant[numarCuvinte][strlen(cuvant[numarCuvinte]) - 1] == '.') {
			cuvant[numarCuvinte][strlen(cuvant[numarCuvinte]) - 1] = '\0';
			break;
		}
		numarCuvinte++;
	}
	for (int index = 0; index <= numarCuvinte; ++index)
	{
		for(int indexJ = index ; indexJ <= numarCuvinte; ++indexJ)
			if (strlen(cuvant[index]) < strlen(cuvant[indexJ]) || (strlen(cuvant[index]) == strlen(cuvant[indexJ]) && strcmp(cuvant[index], cuvant[indexJ])))
			{
				char aux[200];
				strcpy(aux, cuvant[index]);
				strcpy(cuvant[index], cuvant[indexJ]);
				strcpy(cuvant[indexJ], aux);
			}
	}

	for (int index = 0; index <= numarCuvinte; ++index)
		printf("%s'\n", cuvant[index]);

		/*I went to the library yesterday.*/

	return 0;
}