#pragma once
#include "Dog.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Dog> dogs;

public:
	Repository() {}
	~Repository();
	//adds a Dog to the repository by storing it to the dogs DV
	//returns 0 or 1 to decide if the action was done with success
	int addDog(const Dog& d);
	//deltes a Dog from the repository by deleting it from the dogs DV
	//returns 0 or 1 to decide if the action was done with success
	int deleteDog(const Dog& d);
	//updates a Dog from the repository by changing it's age and source
	//returns 0 or 1 to decide if the action was done with success
	int updateDog(const Dog& d);
	//getter for the DV of dogs
	DynamicVector<Dog> getDogs() const { return dogs; }
};

