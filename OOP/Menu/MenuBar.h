#pragma once
#include "Menu.h"
class MenuBar
{
private:
	Menu menus[10];
	int size;
public:
	MenuBar();
	void print()
	{
		for (int i = 0; i < size; i++)
			menus[i].print();
	}
	void add(Menu& m)
	{
		if (size < 10)
			menus[size++] = m;
	}
	~MenuBar();
};

