#include "UserAdoptionList.h"


UserAdoptionList::UserAdoptionList()
{
	this->current = 0;
}
UserAdoptionList::~UserAdoptionList()
{
	//this->adoptedDogs.~DynamicVector();
	//this->dogs.~DynamicVector();
}
UserAdoptionList::UserAdoptionList(const DynamicVector<Dog> v)
{
	this->current = 0;
	//this->dogs = v.getAllElems();
}

UserAdoptionList::UserAdoptionList(const Repository r)
{
	this->current = 0;
	this->dogs = r.getDogs();
}


Dog UserAdoptionList::getCurrentDog()
{
	if (this->current == this->dogs.getSize())
		this->current = 0;
	Dog* elems = this->dogs.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Dog{};
}

DynamicVector<Dog>& UserAdoptionList::adopt()
{
	/*
	if (this->dogs.getSize() == 0)
		return ;
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
	return this->dogs.getSize() == 0;
}

int UserAdoptionList::addAdoptionList(Dog& d)
{
	return this->adoptedDogs.add(d);
}
void UserAdoptionList::setDogs(DynamicVector<Dog>& v)
{
	this->dogs = v;
}

