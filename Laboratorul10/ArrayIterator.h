#pragma once
template<class T>
class ArrayIterator
{
private:
	int Current; 
public:
	T* p;
	T** pToList;
	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();
	//bool operator= (ArrayIterator<T>&); ?
	friend bool operator != (const ArrayIterator<T>& meProb,const ArrayIterator<T>& other)
	{
		return meProb.p != other.p;
	}
	T* operator *();
};

template<class T>
inline ArrayIterator<T>::ArrayIterator()
{
	this->p = nullptr;
	this->pToList = nullptr;
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator++()
{
	this->pToList++;
	this->p = *this->pToList;
	return *this;
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator--()
{
	this->pToList--;
	this->p = *this->pToList;
	return *this;
}


template<class T>
inline T* ArrayIterator<T>::operator*()
{
	return this->p;
}
