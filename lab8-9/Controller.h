#pragma once
#include "Repository.h"
#include "FileUserAdoptionList.h"

class Controller
{
private:
	Repository repo;
	FileUserAdoptionList* user;
public:
	Controller(const Repository& r, FileUserAdoptionList* u)
	{
		this->repo = r;
		this->user = u;
		this->setDogs(r.getDogs());
	}
	~Controller();
	//getter for the repository
	Repository getRepo() const { return repo; }

	//takes data from the UI, construct a new objects and tells the repository to add it
	void addDogToRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);

	//takes data from the UI and tells the repository to delete the onject corresponding to the data
	void deleteDogFromRepository(const std::string& breed, const std::string& name, const int age);

	//takes data from the UI and tells the repository to update the onject corresponding to the data
	void updateDogFromRepository(const std::string& breed, const std::string& name, const int age,const std::string& source);

	//tells the useradpotionlist to add to the adoption list the current dog
	void adoptCurrentDog();
	//takes the adoption list from the useradoptionlist and deletes all the dogs from the repository
	void adoptDogs();

	//tells the useradoptionlist to go to the next dog in the list
	void nextDog();

	//sets the dogs DV(list of dogs from where the user can adopt) with a DV recived from the UI
	void setDogs(std::vector<Dog>& v);

	//filters the repository by taking only the dogs with a given breed and with the age less than a given value
	std::vector<Dog> filterController(const std::string&breed,const int age);

	//filters the repository by taking only the dogs with the age less than a given value
	std::vector<Dog> Controller::filterController(const int age);
	
	//getter for the user
	FileUserAdoptionList* getUserList() const { return this->user; }

	void saveUserAdoiptionList(const std::string& filename);

	void openUserAdoptionList() const;

};

