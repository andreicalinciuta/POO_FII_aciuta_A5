#include"Array.h"
#include"Greater.h"
#include<iostream>

using std::cout;

template<class T>
int Lower(const T& x, const T& y)
{
	return x < y;
}

int main()
{
	Array<int> myArray(4);
	try {
		myArray += 5;
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	try {
		myArray.Insert(0, 2);
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	Array<int> myArray2(2);
	try {
		myArray2.Insert(0, 3);
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	try {
		myArray2.Insert(0, 77);
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	try {
		myArray.Insert(0, myArray2);
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	try {
		myArray.Delete(0);
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	myArray.Sort();

	cout << "Position of element 2 in myArray: " << myArray.BinarySearch(2)<<'\n';

	for (ArrayIterator<int> it = myArray.GetBeginIterator(); it != myArray.GetEndIterator(); ++it)
	{
		cout << *it.p << ' ';
	}
	cout << '\n';

	Compare *f = new Greater();
	myArray.Sort(f);

	for (ArrayIterator<int> it = myArray.GetBeginIterator(); it != myArray.GetEndIterator(); ++it)
	{
		cout << *it.p << ' ';
	}
	cout << '\n';
	try {
		cout << myArray.Find(321) << '\n';
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	try {
		cout << myArray[-321] << '\n';
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	auto func = Lower<int>;
	myArray.Sort(func);

	for (ArrayIterator<int> it = myArray.GetBeginIterator(); it != myArray.GetEndIterator(); ++it)
	{
		cout << *it.p << ' ';
	}
	cout << '\n';
	
	return 0;
}