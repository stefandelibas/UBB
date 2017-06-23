#pragma once
#include "MenuItem.h"
class Menu : public MenuItem
{
	MenuItem* items[10];
	int size;
public:
	Menu() {};
	Menu(std::string n);
	Menu(std::string n, Action* a);
	void add(MenuItem* m)
	{
		if(size < 10)
			items[size++] = m;
	}
	void print() override
	{
		std::cout << this->name << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << "\t";
			items[i]->print();
			std::cout << "\n";
		}
	}
	~Menu();
};

