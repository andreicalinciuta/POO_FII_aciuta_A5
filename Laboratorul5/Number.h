#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Number
{
	char* value;
	int base;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const char* value);
	Number(const Number& x);
	Number(Number&& x);
	Number();
	~Number();


	friend Number operator+(const Number& x, const Number& y);
	friend Number operator-(const Number& x, const Number& y);

	void operator!();
	char operator[](int index);
	bool operator>(const Number& x);
	bool operator<(const Number& x);
	bool operator>=(const Number& x);
	bool operator<=(const Number& x);
	bool operator==(const Number& x);

	bool operator>(int x);
	bool operator<(int x);
	bool operator>=(int x);
	bool operator<=(int x);
	bool operator==(int x);

	void operator--();
	void operator--(int val);

	Number& operator=(Number&& x);
	Number& operator=(int x);
	void operator+=(Number& x);

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};