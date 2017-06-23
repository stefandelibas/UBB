#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository &repo;
public:
	Controller(Repository &r) :repo{ r } {}
	void addSource(std::string name, std::string creator);

	//std::string getStatus(std::string sourceName) { return this->repo.getStatusOF(sourceName); }
	void revise(std::string &sorceName, std::string &reviewer) { this->repo.reviseOne(sorceName, reviewer); }
	int	getToRevise(std::string name) { return repo.getToRevise(name); }
	int getRevised(std::string name) { return repo.getRevised(name); }
	Repository getRepo() { return this->repo; }
	void storeSourceFile() { this->repo.storeSorceFiles(); }
	~Controller();
};

