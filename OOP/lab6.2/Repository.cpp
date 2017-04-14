#include "Repository.h"
#include <string>


Repository::~Repository()
{
}

int Repository::addDog(const Dog& d)
{
	return this->dogs.add(d);
}
int Repository::deleteDog(const Dog& d)
{
	return this->dogs.delete_TElement(d);
}

int Repository::updateDog(const Dog& d)
{
	return this->dogs.update(d);
}

