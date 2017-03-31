#pragma once
#include "DynamicVector.h"
class Shelter
{
private:
	DynamicVector dogs;
	int current;

public:
	Shelter();

	void add(const Dog& song);

	Dog Shelter::getCurrentDog();

	void adopt();

	void next();

	bool isEmpty();
	
};

