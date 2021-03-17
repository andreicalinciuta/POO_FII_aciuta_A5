#include"Number.h"

int max(int x, int y)
{
	return x > y ? x : y;
}

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

int toDeci(char* str, int base)
{
	int len = strlen(str);
	int power = 1; // Initialize power of base 
	int num = 0;  // Initialize result 
	int i;

	// Decimal equivalent is str[len-1]*1 + 
	// str[len-2]*base + str[len-3]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be 
		// less than number's base 
		if (val(str[i]) >= base)
		{
			printf("Invalid Number %s cuz of %c is not %d \n", str, str[i], base);
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	return num;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void strev(char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

// Function to convert a given decimal number 
// to a base 'base' and 
void fromDeci(char* res, int base, int inputNum)
{
	int index = 0;  // Initialize index of result 

	// Convert input number is given base by repeatedly 
	// dividing it by base and taking remainder 
	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);
}

void Number::SwitchBase(int newBase)
{
	int newNumberInDecimal = toDeci(this->value, this->base);

	char* newString;
	newString = (char*)malloc(255 * sizeof(char));
	fromDeci(newString, newBase, newNumberInDecimal);
	newString = (char*)realloc(newString, (strlen(newString) + 1 ) * sizeof(char));

	this->value = (char*)realloc(this->value, (strlen(newString) + 1) * sizeof(char));
	strcpy_s(this->value, strlen(newString) + 1, newString);
	this->base = newBase;
}

Number::Number(const char* value, int base)
{
	if (base >= 2 && base <= 16)
	{
		this->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
		this->base = base;
		strcpy_s(this->value, strlen(value) + 1,  value);
	}
	else
	{
		this->value = nullptr;
		this->base = 0;
	}
}
Number::Number(int value)
{
	char* newString;
	newString = (char*)malloc(255 * sizeof(char));
	fromDeci(newString, 10, value);
	newString = (char*)realloc(newString, (strlen(newString) + 1) * sizeof(char));

	this->value = (char*)realloc(this->value, (strlen(newString) + 1) * sizeof(char));
	strcpy_s(this->value, strlen(newString) + 1, newString);
	this->base = 10;
}
Number::Number(const char* value)
{
	this->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
	this->base = 10;
	strcpy_s(this->value, strlen(value) + 1, value);
}
Number::~Number()
{
	if (this->value != nullptr)
	{
		free(this->value);
		this->base = 0;
	}
}
Number::Number(const Number& x)
{
	this->value = (char*)malloc((strlen(x.value) + 1) * sizeof(char));
	this->base = x.base;
	strcpy_s(this->value, strlen(x.value) + 1, x.value);
}
Number::Number(Number&& x)
{
	char* temp = x.value;
	this->base = x.base;
	x.value = nullptr;
	this->value = temp;
}
Number& Number::operator=(Number&& x)
{
	this->value = (char*)malloc((strlen(x.value) + 1) * sizeof(char));
	this->base = x.base; 
	strcpy_s(this->value, strlen(x.value) + 1, x.value);
	x.value = nullptr;
	x.base = 0;
	return (*this);
}

Number& Number::operator=(int x)
{
	char* newString;
	newString = (char*)malloc(255 * sizeof(char));
	fromDeci(newString, this->base, x);
	newString = (char*)realloc(newString, (strlen(newString) + 1) * sizeof(char));

	this->value = (char*)realloc(this->value, (strlen(newString) + 1) * sizeof(char));
	strcpy_s(this->value, strlen(newString) + 1, newString);
	return (*this);
}

void Number::operator+=(Number& x)
{
	int newBase = max(x.base, this->base);
	int sumOfTheValues = toDeci(x.value, x.base);
	int yToDeci = toDeci(this->value, this->base);

	sumOfTheValues += yToDeci;

	this->value = (char*)malloc(255 * sizeof(char));
	fromDeci(this->value, newBase, sumOfTheValues);
	this->value = (char*)realloc(this->value, (strlen(this->value) + 1) * sizeof(char));


	this->base = newBase;
}

Number operator+(const Number& x, const Number& y)
{

	int newBase = max(x.base, y.base);
	int sumOfTheValues = toDeci(x.value, x.base);
	int yToDeci = toDeci(y.value, y.base);

	sumOfTheValues += yToDeci;

	char* newString;
	newString = (char*)malloc(255 * sizeof(char));
	fromDeci(newString, newBase, sumOfTheValues);
	newString = (char*)realloc(newString, (strlen(newString) + 1) * sizeof(char));


	Number res(newString, newBase);

	return res;
}
Number operator-(const Number& x, const Number& y)
{
	int newBase = max(x.base, y.base);
	int sumOfTheValues = toDeci(x.value, x.base);
	int yToDeci = toDeci(y.value, y.base);

	sumOfTheValues -= yToDeci;

	char* newString;
	newString = (char*)malloc(255 * sizeof(char));
	fromDeci(newString, newBase, sumOfTheValues);
	newString = (char*)realloc(newString, (strlen(newString) + 1) * sizeof(char));


	Number res(newString, newBase);

	return res;
}


void Number::Print()
{
	printf("Number: %s \nBase: %d \n\n", this->value, this->base);
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int Number::GetBase()
{
	return this->base;
}

char* Number::operator!()
{
	return nullptr;
}

char Number::operator[](int index)
{
	int stringLength = strlen(this->value);
	if(index < stringLength)
		return this->value[index];
}

bool Number::operator>(const Number& x)
{
	int thisToDeci = toDeci(this->value, this->base);
	int xToDeci = toDeci(x.value, x.base);
	if (thisToDeci > xToDeci)
		return true;
	return false;
}

bool Number::operator<(const Number& x)
{
	int thisToDeci = toDeci(this->value, this->base);
	int xToDeci = toDeci(x.value, x.base);
	if (thisToDeci < xToDeci)
		return true;
	return false;
}

bool Number::operator>=(const Number& x)
{
	int thisToDeci = toDeci(this->value, this->base);
	int xToDeci = toDeci(x.value, x.base);
	if (thisToDeci >= xToDeci)
		return true;
	return false;
}

bool Number::operator<=(const Number& x)
{
	int thisToDeci = toDeci(this->value, this->base);
	int xToDeci = toDeci(x.value, x.base);
	if (thisToDeci <= xToDeci)
		return true;
	return false;
}

bool Number::operator==(const Number& x)
{
	int thisToDeci = toDeci(this->value, this->base);
	int xToDeci = toDeci(x.value, x.base);
	if (thisToDeci == xToDeci)
		return true;
	return false;
}

void Number::operator--()
{
	int stringLength = strlen(this->value);
	for (int index = 0; index < stringLength; ++index)
		this->value[index] = this->value[index + 1];
	this->value[stringLength - 1] = '\0';
}

void Number::operator--(int val)
{
	int stringLength = strlen(this->value);
	this->value[stringLength - 1] = '\0';
}
