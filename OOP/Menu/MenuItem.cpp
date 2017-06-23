#include "MenuItem.h"



MenuItem::MenuItem(std::string n,Action* a)
{
	this->name = n;
	this->action = a;
}


MenuItem::~MenuItem()
{
}
