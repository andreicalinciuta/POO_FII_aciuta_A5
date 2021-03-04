#include "Math.h"
#include<stdarg.h>
#include<stdio.h>
#include <cstdarg>
#include<string.h>
#include <stdlib.h>

int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	va_list pargs;
	int sum = 0;

	va_start(pargs, count);
	for (int i = 0; i < count; ++i)
		sum += va_arg(pargs, int);
	va_end(pargs);
	return sum;
}

char* Math::Add(const char* textA, const char* textB)
{
	int strlenA = strlen(textA);
	int strlenB = strlen(textB);
	if (strlenA * strlenB== 0)
		return nullptr;
	char* result = (char *) malloc(strlenA + strlenB + 1); // Poate nu are final

	/*for (int i = 0; i < strlenA; ++i)
		result[i] = textA[i];
	for (int i = 0; i < strlenB; ++i)
		result[i + strlenA] = textB[i];
	result[strlenA + strlenB] = '\0';*/

	// Sau

	memset(result, 0, strlenA + strlenB + 1);
	memcpy(result, textA, strlenA);
	memcpy(result + strlenA, textB, strlenB);

	return result;
}
