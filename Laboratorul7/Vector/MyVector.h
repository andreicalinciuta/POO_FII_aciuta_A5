#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

template <typename T>
T compareElementsByOddRule(T x, T y)
{
	return  x * T(5) % T(37) < y * T(3) % T(51);
}

template<typename T>
bool compareElements(T x, T y)
{
	return x % T(10) == y % T(10);
}

template <class T>
class MyVector
{

	int size;
	int memo;
	T* elements;
public:
	MyVector();
	~MyVector();
	void push(T element);
	T pop();
	void remove(int index);
	void insert(T element, int index);
	void sort(T(*callback)(T, T));
	const T& get(int index);
	void set(T element, int index);
	int count();
	int firstIndexOf(T element, bool(*callback)(T, T));
	void Print();
};

template<class T>
inline MyVector<T>::MyVector():memo(1)
{
	this->elements = (T*)malloc(memo * sizeof(this->elements));
	this->size = -1;
}

template<class T>
inline MyVector<T>::~MyVector()
{
	free(elements);
}

template<class T>
inline void MyVector<T>::push(T element)
{
	if (this->size == memo - 1)
	{
		memo *= 2;
		this->elements = (T*)realloc(this->elements, memo * sizeof(this->elements));
	}
	this->size++;
	this->elements[this->size] = element;
}

template<class T>
inline T MyVector<T>::pop()
{
	this->size--;
	return this->elements[ this->size + 1 ];
}

template<class T>
inline void MyVector<T>::remove(int index)
{
	if (index >= 0 && index <= this->size) {
	for (int index1 = index; index1 < this->size; ++index1)
	{
		this->elements[index1] = this->elements[index1 + 1];
	}
	this->size--;

	}
}

template<class T>
inline void MyVector<T>::insert(T element, int index)
{
	if (index >= 0 && index <= this->size + 1) {

	if (this->size == memo)
	{
		memo *= 2;
		this->elements = (T*)realloc(this->elements, memo * sizeof(this->elements));
	}
	this->size++;

	for (int index1 = this->size; index1 > index; --index1)
	{
		this->elements[index1] = this->elements[index1 - 1];
	}
	this->elements[index] = element;
	}
}

template<class T>
inline void MyVector<T>::sort(T(*callback)(T, T))
{
	for (int index1 = 0; index1 <= this->size; ++index1)
	{
		for (int index2 = index1 + 1; index2 <= this->size; ++index2)
		{
			if (callback != nullptr )
			{
				if (callback(this->elements[index1], this->elements[index2]))
				{
					T aux = this->elements[index1];
					this->elements[index1] = this->elements[index2];
					this->elements[index2] = aux;
				}
			}
			else if (this->elements[index1] > this->elements[index2])
			{
				T aux = this->elements[index1];
				this->elements[index1] = this->elements[index2];
				this->elements[index2] = aux;
			}
		}
	}
}

template<class T>
inline const T& MyVector<T>::get(int index)
{
	return this->elements[index];
}

template<class T>
inline void MyVector<T>::set(T element, int index)
{
	this->elements[index] = element;
}

template<class T>
inline int MyVector<T>::count()
{
	return this->size + 1;
}

template<class T>
inline int MyVector<T>::firstIndexOf(T element, bool(*callback)(T, T))
{
	for (int index1 = 0; index1 <= this->size; ++index1)
	{
		if (callback != nullptr)
		{
			if (callback(element, this->elements[index1]))
			{
				return index1;
			}
		}
		else
			if (element == this->elements[index1])
				return index1;
	}
	return -1;
}

template<class T>
inline void MyVector<T>::Print()
{
	for (int index = 0; index <= 60; ++index)
		printf("-");
	printf("\n");
	for (int index = 0; index <= this->size; ++index)
		std::cout << this->elements[index] << ' ';
	printf("\n");
	printf("\n");
}
