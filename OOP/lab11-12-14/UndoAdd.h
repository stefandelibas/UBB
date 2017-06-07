#pragma once
#include"UndoAction.h"
#include"Dog.h"
#include"Repository.h"
class UndoAdd:public UndoAction
{
private:
	Dog dogAdded;
	Repository& repo;
public:
	UndoAdd(Repository& _repo, const Dog& s) :repo{ _repo }, dogAdded{ s }{}
	~UndoAdd();
	void executeUndo() override
	{
		this->repo.deleteDog(dogAdded);
	}
};

