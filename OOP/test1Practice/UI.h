#pragma once
#include "Controller.h"
#include <string>
class UI
{
private:
	Controller ctrl;
public:
	UI();
	UI(const Controller& c): ctrl(c){}
	void printMenu();
	int addMenu();
	void displayAllUI();
	int markAsDoneUI();
	int setPriceUI();
	void filterDate();
	void runUI();
	~UI();
};

