#include "Student.h"
#include<string.h>

void Student::setName(char* name)
{
	strcpy_s(this->name, 20, name);
}

char* Student::getName()
{
	return this->name;
}

void Student::setGradeEnglish(float gradeEnglish)
{
	this->gradeEnglish = gradeEnglish;
}

float Student::getEnglishGrade()
{
	return this->gradeEnglish;
}

void Student::setGradeMath(float gradeMath) 
{
	this->gradeMath = gradeMath;
}

float Student::getMathGrade()
{
	return this->gradeMath;
}

void Student::setGradeHistory(float gradeHistory)
{
	this->gradeHistory = gradeHistory;
}

float Student::getHistoryGrade()
{
	return this->gradeHistory;
}

float Student::getAverageGrade()
{
	return (this->gradeEnglish + this->gradeHistory + this->gradeMath) / 3.0;
}

Student::Student() {

}

Student::~Student() {

}