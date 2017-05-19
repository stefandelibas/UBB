#pragma once
#include "Repository.h"

class UserAdoptionList
{
protected:
	std::vector<Dog> dogs;
	std::vector<Dog> adoptedDogs;
	int current;

public:
	UserAdoptionList();
	virtual ~UserAdoptionList() {};

	// initialize the dogs list(list of dogs from where the user can adopt) with the whole repository
	UserAdoptionList(const Repository r);

	// initialize the dogs vector(list of dogs from where the user can adopt) with a vector
	UserAdoptionList(const std::vector<Dog> v);

	//returns the current Dog in the list while iterating
	Dog getCurrentDog();

	// adopts all the dogs in the user's adoption list so far.
	std::vector<Dog>& adopt();

	//goes to the next Dog in the list 
	void next();

	//sets the dogs DV(list of dogs from where the user can adopt) - for filtering the repository
	void setDogs(std::vector<Dog>& v);

	//check if the dogs DV(list of dogs from where the user can adopt) is empty
	bool isEmpty();

	// adds the current dog to the adoption list of the user
	void addAdoptionList(Dog& d);

	//finds a the index of a dog in the vector, returns -1 if it does not exist.
	int findDog(const Dog d);

	// getter for the adopted dogs
	std::vector<Dog> getDogs() const { return adoptedDogs; }

};