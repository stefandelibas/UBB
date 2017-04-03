#pragma once
#include "DynamicVector.h"
#include "Repository.h"

class UserAdoptionList
{
private:
	DynamicVector<Dog> dogs;
	DynamicVector<Dog> adoptedDogs;
	int current;

public:
	UserAdoptionList();

	// initialize the dogs DV(list of dogs from where the user can adopt) with the whole repository
	UserAdoptionList(const Repository r);

	// initialize the dogs DV(list of dogs from where the user can adopt) with a DV
	UserAdoptionList(const DynamicVector<Dog> v);

	//returns the current Dog in the list while iterating
	Dog getCurrentDog();

	// adopts all the dogs in the user's adoption list so far.
	DynamicVector<Dog>& adopt();

	//goes to the next Dog in the list 
	void next();

	//sets the dogs DV(list of dogs from where the user can adopt) - for filtering the repository
	void setDogs(DynamicVector<Dog>& v);

	//check if the dogs DV(list of dogs from where the user can adopt) is empty
	bool isEmpty();

	// adds the current dog to the adoption list of the user
	int addAdoptionList(Dog& d);

	// getter for the adopted dogs
	DynamicVector<Dog> getDogs() const { return adoptedDogs; }

};