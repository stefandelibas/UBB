#pragma once
#include "Controller.h"
#include "Validator.h"
class UI
{
private:
	Controller ctrl;
	Validator validator;
public:
	UI(const Controller& c) : ctrl(c) {}
	~UI();
	void run(int instances);
private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void printAdoptionMenu();
	void addDogToRepoUI();
	void deleteDogFromRepoUI();
	void updateDogFromRepoUI();
	void displayAllDogsRepo();
	void displayAllDogsAdopted();
	void saveUserAdoptionListToFile();
	std::vector<Dog> FilterUI();

};

