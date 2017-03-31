#pragma once
#include "Dog.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector dogs;

public:
	Repository() {}

	void addDog(const Dog& d);

	void deleteDog(const Dog& d);

	void updateDog(const Dog& d);

	DynamicVector getDogs() const { return dogs; }
};

