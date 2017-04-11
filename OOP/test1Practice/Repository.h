#pragma once
#include "DynamicVector.h"
#include "Project.h"
class Repository
{
private:
	DynamicVector<Project> projects;
public:
	Repository();

	int addProject(Project p);

	DynamicVector<Project> getProjects() { return projects; }
	int setPriceRepo(Project p, int price);
	int DoneProject(Project p);
	Project getElem(int poz);
	~Repository();
};

