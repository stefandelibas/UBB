#include "Project.h"



Project::Project()
{
}

Project::Project(const std::string name, const std::string customer, const std::string date, const double price, const bool isDone)
{
	this->name = name;
	this->customer = customer;
	this->date = date;
	this->price = price;
	this->isDone = isDone;
}


int Project::setDone()
{
	if (!isDone)
	{
		this->isDone = true;
		return 1;
	}
	return 0;
}

void Project::setPrice(int price)
{
	this->price = price;

}

bool Project::operator==(Project p)
{
	return this->getName() == p.getName() && this->getCustomer() == p.customer;
}

Project::~Project()
{
}
