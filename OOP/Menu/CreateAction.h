#pragma once
#include "Action.h"
#include <iostream>
class CreateAction :
	public Action
{
public:
	CreateAction();
	void execute() override
	{
		std::cout << "Create file.\n";
	}
	~CreateAction();
};

