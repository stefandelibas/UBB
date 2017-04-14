#pragma once
#include "Dog.h"

/*
typedef Dog TElement;

class DynamicVector
{

private:
	TElement* elems;
	int size;
	int capaity;

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& v);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& v);
	void add(const TElement& e);
	void delete_TElement(const TElement& e);
	void update(const TElement& e);
	int getSize() const;
	TElement* getAllElems()const;
private:
	void resize(double factor = 2);

};
*/


#pragma once

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;
public:
	//constructor with a initial capacity
	DynamicVector(int capacity = 10);
	//copy of a dynamic vector
	DynamicVector(const DynamicVector& v);
	//destructor
	~DynamicVector();
	//overloading over the operator = for assigning to a DV another DV
	DynamicVector& operator=(const DynamicVector& v);
	//overloading ove the operator = for getting an element on a given position
	T& operator[](int pos);
	//getter for the size of the DV
	DynamicVector<T>& DynamicVector<T>::operator-(const T& e);
	int getSize() const;
	//getter for all the elements stored by the DV
	T* getAllElems()const;
	// adds an element of Type T in the DV and returns 0 or 1 to decide if the action was done with success
	int add(T e);
	// deletes an element of Type T in the DV and returns 0 or 1 to decide if the action was done with success
	int delete_TElement(const T& e);
	// updates an element of Type T in the DV and returns 0 or 1 to decide if the action was done with success
	int update(const T& e);
	//searches an element of type T in the DV and returns -1 if it was not found and the position if it was found
	int find(const T& e);
private:
	//resizes the DA by expanding the capacity
	void resize(double factor = 2);
};

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator-(const T& e)
{
	int i = find(e);
	if (i != -1)
	{
		for (int j = i; j < this->size - 1; j++)
			this->elems[j] = this->elems[j + 1];
		this->size--;
	}
	return *this;
}
template <typename T>
DynamicVector<T>::DynamicVector(int capacity = 10)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
int DynamicVector<T>::find(const T& e)
{
	int i;
	for (i = 0; i < this->size; i++)
	{
		if (this->elems[i] == e)
			return i;
	}
	return -1;
}
template <typename T>
int DynamicVector<T>::delete_TElement(const T& e)
{
	int i = find(e);
	if (i == -1)
		return 0;
	*this-e;
	return 1;
}

template <typename T>
int DynamicVector<T>::update(const T& e)
{
	int i = find(e);
	if (i == -1)
		return 0;
	this->elems[i] = e;
	return 1;
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
int DynamicVector<T>::add(T e)
{
	int i = find(e);
	if (i != -1)
		return 0;
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = e;
	return 1;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;
	T* elements = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		elements[i] = this->elems[i];

	delete[] this->elems;
	this->elems = elements;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}
template <typename T>
T* DynamicVector<T>::getAllElems() const
{
	return this->elems;
}


