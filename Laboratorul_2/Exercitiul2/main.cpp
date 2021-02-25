#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "Student.h"
#include "Sort.h"
using namespace std;

int main()
{
	Student first;
	first.setName((char *)"Mark");
	first.setGradeEnglish(4.3);
	first.setGradeHistory(5.6);
	first.setGradeMath(8.3);
	printf("Studentul %s are notele: \n Mate - %1.2f \n Engleza - %1.2f \n Istorie - %1.2f \n Media: %1.2f\n", first.getName(), first.getMathGrade(),
		first.getEnglishGrade(), first.getHistoryGrade(),
		first.getAverageGrade());

	Student second;
	second.setName((char*)"Richard");
	second.setGradeEnglish(7.8);
	second.setGradeHistory(4.9);
	second.setGradeMath(8.3);
	printf("Studentul %s are notele: \n Mate - %1.2f \n Engleza - %1.2f \n Istorie - %1.2f \n Media: %1.2f\n", second.getName(), second.getMathGrade(),
		second.getEnglishGrade(), second.getHistoryGrade(),
		second.getAverageGrade());
	printf("Studentul %s vs Studentul %s\n Nume: %d \n Engleza: %d \n Istorie: %d \n  Mate: %d \n Media: %d",first.getName(), second.getName(),
		SortByName(&first, &second), SortByEnglish(&first, &second), SortByHistory(&first, &second), SortByMath(&first, &second), SortByAverage(&first, &second));
}