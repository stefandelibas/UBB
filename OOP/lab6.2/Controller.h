#pragma once
#include "Repository.h"
#include "UserAdoptionList.h"

class Controller
{
private:
	Repository repo;
	UserAdoptionList user;
public:
	Controller(const Repository& r, UserAdoptionList& u)
	{
		this->repo = r;
		this->user = u;
	}
	~Controller();
	//getter for the repository
	Repository getRepo() const { return repo; }

	//takes data from the UI, construct a new objects and tells the repository to add it
	int addDogToRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);

	//takes data from the UI and tells the repository to delete the onject corresponding to the data
	int deleteDogFromRepository(const std::string& breed, const std::string& name, const int age);

	//takes data from the UI and tells the repository to update the onject corresponding to the data
	int updateDogFromRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);

	//tells the useradpotionlist to add to the adoption list the current dog
	int adoptCurrentDog();
	//takes the adoption list from the useradoptionlist and deletes all the dogs from the repository
	void adoptDogs();

	//tells the useradoptionlist to go to the next dog in the list
	void nextDog();

	//sets the dogs DV(list of dogs from where the user can adopt) with a DV recived from the UI
	void setDogs(DynamicVector<Dog>& v);

	//filters the repository by taking only the dogs with a given breed and with the age less than a given value
	DynamicVector<Dog> filterController(const std::string&breed,const int age);

	//filters the repository by taking only the dogs with the age less than a given value
	DynamicVector<Dog> Controller::filterController(const int age);
	
	//getter for the user
	UserAdoptionList getUserList() const { return this->user; }

};

