#include "Menu.h"



Menu::Menu(std::string n)
{
	this->name = n;
	this->size = 0;
}


Menu::Menu(std::string n, Action * a)
{
	this->name = n;
	this->size = 0;
	this->action = a;
}

Menu::~Menu()
{
}
