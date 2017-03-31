#include "Shelter.h"



Shelter::Shelter()
{
	this->current = 0;
}

Dog Shelter::getCurrentDog()
{
	if (this->current == this->dogs.getSize())
		this->current = 0;
	Dog* elems = this->dogs.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Dog{};
}

void Shelter::add(const Dog& dog)
{
	this->dogs.add(dog);
}

void Shelter::adopt()
{
	if (this->dogs.getSize() == 0)
		return;
	this->current = 0;
	Dog currentDog = this->getCurrentDog();
	currentDog.showPhoto();
}
void Shelter::next()
{
	if (this->dogs.getSize() == 0)
		return;
	this->current++;
	Dog currentDog = this->getCurrentDog();
	currentDog.showPhoto();
}
bool Shelter::isEmpty()
{
	return this->dogs.getSize() == 0;
}