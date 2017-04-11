#include "Controller.h"



Controller::Controller()
{
}


int Controller::addToRepository(const std::string name, const std::string customer, const std::string date, const double price, const bool isDone)
{
	Project p{ name,customer,date,price,isDone };
	return this->repo.addProject(p);
}

int Controller::changePrice(const std::string name, const std::string customer, double price)
{
	Project p{ name,customer,"",0,false };
	return this->repo.setPriceRepo(p, price);
}

int Controller::markAsDone(const std::string name, const std::string customer)
{
	Project p{ name,customer,"",0,false };
	return this->repo.DoneProject(p);
}

DynamicVector<Project> Controller::filterDateCtrl(const std::string date)
{
	DynamicVector<Project> r = this->filterUndone();
	DynamicVector<Project> v;

	for (int i = 0; i < r.getSize(); i++)
	{
		Project p = r[i];
		if (p.getDate() > date)
		{
			v.add(p);
		}
	}
	return v;
}

DynamicVector<Project> Controller::filterUndone()
{
	DynamicVector<Project> v;

	for (int i = 0; i < this->repo.getProjects().getSize(); i++)
	{
		Project p = this->repo.getElem(i);
		if (!p.getIsDone())
		{
			v.add(p);
		}
	}
	return v;
}

Controller::~Controller()
{
}
