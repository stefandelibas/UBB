#include "Repository.h"



Repository::Repository()
{
}

int Repository::addProject(Project p)
{
	return this->projects.add(p);
}

int Repository::setPriceRepo(Project p, int price)
{
	int poz = this->projects.find(p);
	if(poz!=-1)
	{
		this->projects[poz].setPrice(price);
		return 1;
	}
	return 0;
}

int Repository::DoneProject(Project p)
{
	int i = this->projects.find(p);
	if (i == -1)
		return 0;
	int j = this->projects[i].setDone();
	if (!j)
		return 1;
	return -1;
}

Project Repository::getElem(int poz)
{
	return this->projects[poz];
}

Repository::~Repository()
{
}
