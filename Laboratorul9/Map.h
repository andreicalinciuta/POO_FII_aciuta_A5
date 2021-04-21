#pragma once
#include<iostream>
#include"MyIterator.h"
#include"Elements.h"

using std::cout;


template<class T, class R>
class Map
{
private:
	Elements<T,R>* elements;
	int capacity;
	int numberOfElements;
public:
	Map();
	R& operator[](T);
	void printForTest();
	Elements<T,R>* begin();
	Elements<T,R>* end();
	void Set(T key,R value);
	bool Get(const T& key, R& value) const;
	int Count() const;
	void Clear();
	bool Delete(const T& key);
	bool Includes(const Map<T, R>& map);
};

template<class T, class R>
inline Map<T, R>::Map():capacity(1),numberOfElements(0)
{
	this->elements = (Elements<T, R>*)malloc(sizeof(Elements<T, R>) * this->capacity);
}



template<class T, class R>
inline R& Map<T, R>::operator[](T key)
{
	for (int i = 0; i < this->numberOfElements; ++i)
	{
		if (this->elements[i].key == key)
		{
			return this->elements[i].value;
		}
	}
	if (this->numberOfElements == this->capacity)
	{
		this->capacity *= 2;
		this->elements = (Elements<T, R>*)realloc(this->elements, sizeof(Elements<T, R>) * this->capacity);
	}
	this->elements[this->numberOfElements].key = key;
	this->elements[this->numberOfElements].index = this->numberOfElements;

	this->numberOfElements++;
	return this->elements[this->numberOfElements - 1].value;
}

template<class T, class R>
inline void Map<T, R>::printForTest()
{
	for (int i = 0; i < this->numberOfElements; ++i)
		cout << this->elements[i].value << ' ' << this->elements[i].key << ' ' << this->elements[i].index << '\n';;
	cout << '\n';
}

template<class T, class R>
inline Elements<T,R>* Map<T, R>::begin()
{
	return &this->elements[0];
}

template<class T, class R>
inline Elements<T,R>* Map<T, R>::end()
{
	return &this->elements[this->numberOfElements];
}

template<class T, class R>
inline void Map<T, R>::Set(T key, R value)
{
	for (int i = 0; i < this->numberOfElements; ++i)
	{
		if (this->elements[i].key == key)
		{
			this->elements[i].key = key;
		}
	}
}

template<class T, class R>
inline bool Map<T, R>::Get(const T& key, R& value)const
{

	for (int i = 0; i < this->numberOfElements; ++i)
	{
		if (this->elements[i].key == key)
		{
			value = this->elements[i].value;
			return true;
		}
	}
	return false;
}

template<class T, class R>
inline int Map<T, R>::Count() const
{
	return this->numberOfElements;
}

template<class T, class R>
inline void Map<T, R>::Clear()
{
	delete[] this->elements;
	this->numberOfElements = 0;
}

template<class T, class R>
inline bool Map<T, R>::Delete(const T& key)
{
	for (int i = 0; i < this->numberOfElements; ++i)
	{
		if (this->elements[i].key == key)
		{
			for (int j = i + 1; j < this->numberOfElements; ++j)
				this->elements[j - 1] = this->elements[j];
			return true;
		}
	}
	return false;
}

template<class T, class R>
inline bool Map<T, R>::Includes(const Map<T, R>& map)
{
	if (this->numberOfElements == map.Count())
	{
		for (int i = 0; i < this->numberOfElements; ++i)
		{
			R x;
			if ( !map.Get(this->elements[i].key, x) )
			{
				return false;
			}
		}
	}
	return true;
}



