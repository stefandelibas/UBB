#pragma once
#include "Action.h"
#include <iostream>

class ExitAction :
	public Action
{
public:
	ExitAction();
	void execute() override
	{
		std::cout << "Exit application.\n";
	}
	~ExitAction();
};

