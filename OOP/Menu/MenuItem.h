#pragma once
#include <string>
#include "Action.h"
#include <iostream>
class MenuItem
{
protected:
	std::string name;
	Action * action;

public:
	MenuItem(){}
	MenuItem(std::string n,Action* a);
	virtual void print()
	{
		std::cout << "\t";
		std::cout << this->name;
	}
	void clicked()
	{
		this->print();
		this->action->execute();
	}
	virtual ~MenuItem();
};

