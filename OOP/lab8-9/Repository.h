#pragma once
#include "Dog.h"
#include <vector>

class Repository
{
private:
	std::vector<Dog> dogs;
	std::string file;

public:
	Repository() {};
	Repository(std::string file);
	~Repository();
	//adds a Dog to the repository by storing it to the dogs DV
	//returns 0 or 1 to decide if the action was done with success
	void addDog(const Dog& d);
	//deltes a Dog from the repository by deleting it from the dogs DV
	//returns 0 or 1 to decide if the action was done with success
	void deleteDog(const Dog& d);
	//updates a Dog from the repository by changing it's age and source
	//returns 0 or 1 to decide if the action was done with success
	void updateDog(const Dog& d);
	//finds a the index of a dog in the vector, returns -1 if it does not exist.
	int findDog(const Dog d);
	//getter for the DV of dogs
	std::vector<Dog> getDogs() const { return dogs; }
	//load data from txt file
	void loadFromFile();
	void storeToFile();
};

