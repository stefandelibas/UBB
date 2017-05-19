#include "UserAdoptionList.h"


UserAdoptionList::UserAdoptionList()
{
	this->current = 0;
}
UserAdoptionList::UserAdoptionList(const std::vector<Dog> v)
{
	this->current = 0;
	this->dogs = v;
}

UserAdoptionList::UserAdoptionList(const Repository r)
{
	this->current = 0;
	this->dogs = r.getDogs();
}


Dog UserAdoptionList::getCurrentDog()
{
	if (this->current == this->dogs.size())
		this->current = 0;
	if (dogs.size())
		return this->dogs[this->current];
	return Dog{};
}

std::vector<Dog>& UserAdoptionList::adopt()
{
	/*
	if (this->adoptedDogs.size() == 0)
		return;
	*/
	return this->adoptedDogs;
}

void UserAdoptionList::next()
{
	if (isEmpty())
		return;
	this->current++;
	Dog currentDog = this->getCurrentDog();
	//currentDog.showPhoto();
}
bool UserAdoptionList::isEmpty()
{
	return this->dogs.size() == 0;
}

void UserAdoptionList::addAdoptionList(Dog& d)
{
	int i = this->findDog(d);
	if (i == -1)
	{
		this->adoptedDogs.push_back(d);
	}
	else throw std::invalid_argument("The dog is already in the adoption list!");
}
void UserAdoptionList::setDogs(std::vector<Dog>& v)
{
	this->dogs = v;
}

int UserAdoptionList::findDog(const Dog d)
{
	for (size_t i = 0; i<this->adoptedDogs.size(); i++)
		if (this->adoptedDogs[i] == d){return i;}
	return -1;
}

