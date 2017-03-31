#include "Controller.h"

void Controller::addDogToRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	Dog d{ breed,name,age,source };
	this->repo.addDog(d);
}

void Controller::deleteDogFromRepository(const std::string& breed, const std::string& name, const int age)
{
	Dog d{ breed,name,age,""};
	this->repo.deleteDog(d);
}
void Controller::updateDogFromRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	Dog d{ breed,name,age,source };
	this->repo.updateDog(d);
}
void Controller::addDogToShelter(const Dog& dog)
{

}

void Controller::adoptDogs()
{
	this->shelter.adopt();
}
Controller::~Controller()
{
}
