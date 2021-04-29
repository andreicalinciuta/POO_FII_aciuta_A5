#pragma once
#include"ArrayIterator.h"
#include"OutOfIndexException.h"
#include"FullListException.h"
#include"Compare.h"
#include<iostream>

using std::cout;

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	T& operator[] (int index) const; // arunca exceptie daca index este out of range
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray); // constructor de copiere
	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator=(const Array<T>& otherArray);
	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator
	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
	int GetSize() const;
	int GetCapacity() const;
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
	void PrintTest();
};

template<class T>
inline Array<T>::Array()
{
	this->List = nullptr;
	this->Capacity = 0;
	this->Size = 0;
}

template<class T>
inline Array<T>::~Array()
{
	for (int i = 0; i < this->Size; ++i)
		delete List[i];
	delete[] List;
	Size = 0;
	Capacity = 0;
}

template<class T>
inline Array<T>::Array(int capacity)
{
	this->Capacity = capacity;
	this->Size = 0;
	this->List = new T * [capacity];
}

template<class T>
inline T& Array<T>::operator[](int index) const
{
	if (index > this->Size || index < 0)
	{
		throw OutOfIndexException();
	}
	return *(this->List[index]);
}
template<class T>
inline Array<T>::Array(const Array<T>& otherArray)
{
	this->Size = otherArray.GetSize();
	this->Capacity = otherArray.GetCapacity();
	this->List = new T * [this->Capacity];
	for (int i = 0; i < this->Size; ++i)
	{
		this->List[i] = new T;
		*(this->List[i]) = (otherArray[i]);
	}
}


template<class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (this->Size == this->Capacity)
		throw FullListException();
	this->Insert(Size, newElem);
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (index > this->Size || index < 0)
		throw OutOfIndexException();
	if (this->Size == this->Capacity)
	{
		int newCapacity = this->Capacity * 2;
		T** tmpList = new T * [this->Capacity];
		for (int i = 0; i < this->Size; ++i)
			tmpList[i] = this->List[i];

		this->List = new T * [newCapacity];
		for (int i = 0; i < this->Size; ++i)
			this->List[i] = tmpList[i];

		delete[] tmpList;
		this->Capacity = newCapacity;
	}

	this->List[Size] = new T;
	this->Size++;

	for (int i = this->Size - 1; i > index; --i)
		*this->List[i] = *this->List[i - 1];

	*this->List[index] = newElem;
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (index > this->Size || index < 0)
		throw OutOfIndexException();

	int howMany = otherArray.GetSize();
	int index2 = 0;
	while (howMany)
	{
		this->Insert(index, otherArray[index2]);
		++index;
		++index2;
		--howMany;
	}

	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{
	if (index > this->Size)
		throw OutOfIndexException();
	for (int i = index + 1; i < this->Size; ++i)
		*this->List[i - 1] = *this->List[i];
	this->Size--;
	return *this;
}

template<class T>
inline bool Array<T>::operator=(const Array<T>& otherArray)
{	
	delete[] this->List;
	this->Capacity = otherArray.GetCapacity();
	this->Size = otherArray.GetSize();

	this->List = new T * [this->Capacity];
	for (int i = 0; i < this->Size; ++i)
	{
		this->List[i] = new T;
		*this->List[i] = *otherArray[i];
	}

	return true;
}

template<class T>
inline void Array<T>::Sort()
{
	for(int i = 0 ; i < this->Size ; ++i)
		for(int j = i + 1 ; j < this->Size ; ++j)
			if (*this->List[i] > *this->List[j])
			{
				T aux = *this->List[i];
				*this->List[i] = *this->List[j];
				*this->List[j] = aux;
			}
}

template<class T>
inline void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	for (int i = 0; i < this->Size; ++i)
		for (int j = i + 1; j < this->Size; ++j)
			if (compare(*this->List[i], *this->List[j]))
			{
				T aux = *this->List[i];
				*this->List[i] = *this->List[j];
				*this->List[j] = aux;
			}
}

template<class T>
inline void Array<T>::Sort(Compare* comparator)
{
	for (int i = 0; i < this->Size; ++i)
		for (int j = i + 1; j < this->Size; ++j)
			if (comparator->CompareElements(this->List[i], this->List[j]))
			{
				T aux = *this->List[i];
				*this->List[i] = *this->List[j];
				*this->List[j] = aux;
			}
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem)
{
	int left, right, midd;
	right = this->Size - 1;
	left = 0;
	while (left <= right)
	{
		midd = left + (right - left) / 2;
		if (*this->List[midd] == elem)
			return midd;
		else if (*this->List[midd] > elem)
			right = midd - 1;
		else
			left = midd + 1;
	}
	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	int left, right, midd;
	right = this->Size - 1;
	left = 0;
	while (left <= right)
	{
		midd = left + (right - left) / 2;
		if (*this->List[midd] == elem)
			return midd;
		else if (compare(*this->List[midd], elem))
			right = midd - 1;
		else
			left = midd + 1;
	}
	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	int left, right, midd;
	right = this->Size - 1;
	left = 0;
	while (left <= right)
	{
		midd = left + (right - left) / 2;
		if (*this->List[midd] == elem)
			return midd;
		else if (comparator->CompareElements(*this->List[midd], elem))
			right = midd - 1;
		else
			left = midd + 1;
	}
}

template<class T>
inline int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < this->Size; ++i)
		if (*this->List[i] == elem)
			return i;
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < this->Size; ++i)
		if (compare(*this->List[i], elem))
			return i;
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i = 0; i < this->Size; ++i)
		if (comparator->CompareElements(*this->List[i], elem))
			return i;
	return -1;
}

template<class T>
inline int Array<T>::GetSize() const
{
	return this->Size;
}

template<class T>
inline int Array<T>::GetCapacity() const
{
	return this->Capacity;
}

template<class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator()
{
	ArrayIterator<T> temp;
	temp.p = this->List[0];
	temp.pToList = this->List;
	return temp;
}

template<class T>
inline ArrayIterator<T> Array<T>::GetEndIterator()
{
	ArrayIterator<T> temp;
	temp.p = this->List[this->Size];
	temp.pToList = this->List;
	return temp;
}

template<class T>
inline void Array<T>::PrintTest()
{
	for (int i = 0; i < this->Size; ++i)
		cout << *this->List[i] << ' ';
	cout << '\n';
}
