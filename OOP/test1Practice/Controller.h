#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository repo;
public:
	Controller();
	Controller(const Repository& r) : repo(r){}

	int addToRepository(const std::string name, const std::string customer, const std::string date, const double price, const bool isDone);
	
	Repository getRepo() const { return repo; }
	int changePrice(const std::string name, const std::string customer,double price);
	int markAsDone(const std::string name, const std::string customer);
	DynamicVector<Project> filterDateCtrl(const std::string date);
	DynamicVector<Project> filterUndone();
	~Controller();
};

