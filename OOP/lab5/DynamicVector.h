#pragma once
#include "Dog.h"

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

