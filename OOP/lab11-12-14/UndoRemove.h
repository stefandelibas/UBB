#pragma once
#include"UndoAction.h"
#include"Dog.h"
#include"Repository.h"
class UndoRemove:public UndoAction
{
private:
	Dog dogRemoved;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Dog& s) :repo{ _repo }, dogRemoved{ s } {}
	~UndoRemove();
	void executeUndo() override
	{
		this->repo.addDog(dogRemoved);
	}
};

