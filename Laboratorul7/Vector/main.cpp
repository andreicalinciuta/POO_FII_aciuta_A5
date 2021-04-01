#include "MyVector.h"
#include<iostream>

int main()
{
	MyVector<int> vec;
	vec.push(44);
	vec.Print();
	vec.push(64);
	vec.push(23);
	vec.push(32);
	vec.push(991);
	vec.push(443);
	vec.Print();
	std::cout << "Ultimul element din vector (pop) " << vec.pop() << '\n';
	vec.Print();
	vec.remove(2);
	std::cout << "Am dat remove la indexul 2 " << '\n';
	vec.Print();
	vec.insert(432423, 3);
	std::cout << "Am dat insert la indexul 3 " << '\n';
	vec.Print();
	std::cout << "Am sortat " << '\n';
	vec.sort(compareElementsByOddRule);
	vec.Print();
	std::cout << "Obiectul de pe pozitia 2 este: " << vec.get(2) << '\n';
	vec.set(3, 2);
	vec.Print();
	std::cout << "Elemente in vector: " << vec.count() << '\n';
	std::cout << "Primul element care se termina cu 3 se afla pe pozitia: " << vec.firstIndexOf(3, compareElements) << '\n';
	return 0;
}