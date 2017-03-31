#pragma once
#include "Repository.h"
#include "Shelter.h"

class Controller
{
private:
	Repository repo;
	Shelter shelter;
public:
	Controller(const Repository& r)/*{this->repo = r;}*/: repo(r) {}
	Repository getRepo() const { return repo; }
	Shelter getShelter() const { return shelter; }
	void addDogToRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);
	void deleteDogFromRepository(const std::string& breed, const std::string& name, const int age);
	void updateDogFromRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);
	void addDogToShelter(const Dog& dog);

	void adoptDogs();
	void nextDogShelter();
		
	~Controller();
};

