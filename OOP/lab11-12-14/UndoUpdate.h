#pragma once
#include "UndoAction.h"
#include"Dog.h"
#include"Repository.h"
class UndoUpdate :public UndoAction
{
private:
	Repository &repo;
	Dog oldDog;
public:
	UndoUpdate(Repository&r,const Dog &d):repo{r},oldDog{d}{}
	~UndoUpdate();
	void executeUndo() override
	{
		this->repo.updateDog(oldDog);
	}
};

