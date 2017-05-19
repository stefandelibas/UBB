/*

#include "DynamicVector.h"



DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capaity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capaity = v.capaity;
	this->elems = new TElement[this->capaity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capaity = capaity;

	delete[] this->elems;
	this->elems = new TElement[this->capaity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

void DynamicVector::add(const TElement& e)
{
	if (this->size == this->capaity)
		this->resize();
	this->elems[this->size++] = e;
}

void DynamicVector::delete_TElement(const TElement& e)
{
	int i;
	for (i = 0; i < this->size; i++)
	{
		if (this->elems[i] == e)
			break;
	}
	for (int j = i; j < this->size; j++)
		this->elems[j] = this->elems[j + 1];
	this->size--;
}

void DynamicVector::update(const TElement& e)
{
	int i;
	for (i = 0; i < this->size; i++)
	{
		if (this->elems[i] == e)
		{
			this->elems[i] = e;
			break;
		}
	}
}

void DynamicVector::resize(double factor)
{
	this->capaity *= static_cast<int>(factor);

	TElement* elements = new TElement[this->capaity];
	for (int i = 0; i < this->size; i++)
		elements[i] = this->elems[i];
	delete[] this->elems;
	this->elems = elements;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}
*/