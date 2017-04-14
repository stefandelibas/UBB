#include "Controller.h"

Controller::~Controller()
{
}
int Controller::addDogToRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	Dog d{ breed,name,age,source };
	return this->repo.addDog(d);
}

int Controller::deleteDogFromRepository(const std::string& breed, const std::string& name, const int age)
{
	Dog d{ breed,name,age,""};
	return this->repo.deleteDog(d);
}
int Controller::updateDogFromRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	Dog d{ breed,name,age,source };
	return this->repo.updateDog(d);
}


void Controller::nextDog()
{
	this->user.next();
}
int Controller::adoptCurrentDog()
{
	Dog d = this->user.getCurrentDog();
	return this->user.addAdoptionList(d);
}
void Controller::adoptDogs()
{
	DynamicVector<Dog> v = this->user.adopt();
	for(int i=0;i<v.getSize();i++)
		this->repo.deleteDog(v[i]);
}
DynamicVector<Dog> Controller::filterController(const std::string&breed, const int age)
{
	DynamicVector<Dog> v = this->repo.getDogs();
	DynamicVector<Dog> q{};
	for (int i = 0; i <= v.getSize(); i++)
		if (v[i].getBreed() == breed && v[i].getAge() < age)
			q.add(v[i]);
	return q;
}
DynamicVector<Dog> Controller::filterController(const int age)
{
	DynamicVector<Dog> v = this->repo.getDogs();
	DynamicVector<Dog> q{};
	for (int i = 0; i < v.getSize(); i++)
		if (v[i].getAge() < age)
			q.add(v[i]);
	return q;
}
void Controller::setDogs(DynamicVector<Dog>& v)
{
	this->user.setDogs(v);
}
