#pragma once
class Student
{
private:
	char name[20];
	float gradeMath;
	float gradeEnglish;
	float gradeHistory;
public:
	Student();
	~Student();
	void setName(char* name);
	char* getName();

	void setGradeMath(float gradeMath);
	float getMathGrade();

	void setGradeEnglish(float gradeEnglish);
	float getEnglishGrade();

	void setGradeHistory(float gradeHistory);
	float getHistoryGrade();

	float getAverageGrade();
};

