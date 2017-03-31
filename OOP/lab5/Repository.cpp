#include "Repository.h"
#include <string>


void Repository::addDog(const Dog& d)
{
	this->dogs.add(d);
}
void Repository::deleteDog(const Dog& d)
{
	this->dogs.delete_TElement(d);
}

void Repository::updateDog(const Dog& d)
{
	this->dogs.update(d);
}

