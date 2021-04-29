#pragma once
#include<exception>
using std::exception;
class FullListException: public exception
{
public:
	virtual const char* what() const throw();
};

