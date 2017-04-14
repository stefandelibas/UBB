#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
		
public:
	UI(const Controller& c) : ctrl(c) {}
	~UI();
	void run(int instances);
private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void printAdoptionMenu();
	int addDogToRepoUI();
	int deleteDogFromRepoUI();
	int updateDogFromRepoUI();
	void displayAllDogsRepo();
	void displayAllDogsAdopted();
	DynamicVector<Dog> FilterUI();

};

