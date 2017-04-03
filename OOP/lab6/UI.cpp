#include "UI.h"
#include <string>
#include <cstdio>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator Mode"<<endl;
	cout << "2 - User mode"<<endl;
	cout << "0 - Exit"<<endl;
}

void UI::printAdminMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add a dog." << endl;
	cout << "\t 2 - Delete a dog" << endl;
	cout << "\t 3 - Update a dog" << endl;
	cout << "\t 4 - Show all dogs in database." << endl;
	cout << "\t 0 - Back." << endl;
}
void UI::printUserMenu()
{
	cout << "possible commands: " << endl;
	cout << "\t 1 - show the adoption list.\n";
	cout << "\t 2 - adopt the dogs from the adoption list.\n";
	cout << "\t 3 - start going through the adoption list\n";
	cout << "\t 4 - filter the database\n";
	cout << "\t 0 - back\n";
}

void UI::printAdoptionMenu()
{
	Dog d = this->ctrl.getUserList().getCurrentDog();
	cout << "name:" << d.getName()<<" ";
	cout << "breed:" << d.getBreed()<<" ";
	cout << "age:" << d.getAge()<<endl;
	d.showPhoto();

	cout << "possible commands:" << endl;
	cout << "\t 1 - next dog" << endl;
	cout << "\t 2 - adopt this dog." << endl;
	cout << "\t 0 - exit adoption." << endl;
}
int UI::addDogToRepoUI()
{
	cout << "Enter dog's details." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	cout << "Name:";
	std::string name;
	getline(cin, name);
	cout << "Age:";
	int age;
	cin >> age;
	cin.ignore();
	cout << "photo source:";
	std::string source;
	getline(cin, source);

	return this->ctrl.addDogToRepository(breed, name, age, source);
}


int UI::deleteDogFromRepoUI()
{
	cout << "Enter dog's details." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	cout << "Name:";
	std::string name;
	getline(cin, name);
	cout << "Age:";
	int age;
	cin >> age;
	cin.ignore();

	return this->ctrl.deleteDogFromRepository(breed, name, age);
}

int UI::updateDogFromRepoUI()
{
	cout << "Enter the details of the dog you want to update." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	cout << "Name:";
	std::string name;
	getline(cin, name);

	cout << "Enter the new details of the dog." << endl;
	cout << "New age:";
	int age;
	cin >> age;
	cin.ignore();
	cout << "New photo source:";
	std::string source;
	getline(cin, source);

	return this->ctrl.updateDogFromRepository(breed, name, age, source);
}
void UI::displayAllDogsRepo()
{
	DynamicVector<Dog> v = this->ctrl.getRepo().getDogs();
	Dog* dogs = v.getAllElems();
	if (dogs == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "No dog in the repository." << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() <<endl;
	}
}

void UI::displayAllDogsAdopted()
{
	DynamicVector<Dog> v = this->ctrl.getUserList().getDogs();
	Dog* dogs = v.getAllElems();
	if (dogs == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "No dog in the repository." << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() << endl;
	}
}
DynamicVector<Dog> UI::FilterUI()
{
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	cout << "Age:";
	int age;
	cin >> age;
	cin.ignore();
	if (breed == "")
		return this->ctrl.filterController(age);

	else
	return this->ctrl.filterController(breed, age);
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Inpt the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandAdmin{ 0 };
				cout << "Input the command : ";
				cin >> commandAdmin;
				cin.ignore();
				if (commandAdmin == 0)
					break;
				switch (commandAdmin)
				{
				case 1:
				{
					int i = this->addDogToRepoUI();
					if (i == 0)
						cout << "cannot add.\n";
					else
						cout << "add successfully done.\n";
					break;
				}
				case 2:
				{
					int i = this->deleteDogFromRepoUI();
					if (i == 0)
						cout << "cannot delete.\n";
					else
						cout << "delete successfully done.\n";
					break;
				}
				case 3:
				{
					int i = this->updateDogFromRepoUI();
					if (i == 0)
						cout << "cannot update.\n";
					else
						cout << "update successfully done.\n";
					break;
				}
				case 4:
				{
					this->displayAllDogsRepo();
					break;
				}

				}
			}
		}
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUser{ 0 };
				cout << "Input the command : ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
				{
					this->displayAllDogsAdopted();
					break;
				}
				case 2:
				{
					this->ctrl.adoptDogs();
					break;
				}
				case 3:
				{
					while (true)
					{
						UI::printAdoptionMenu();
						int commandAdoption{ 0 };
						cout << "Input the command : ";
						cin >> commandAdoption;
						cin.ignore();
						if (commandAdoption == 0)
							break;
						if (commandAdoption == 1)
							this->ctrl.nextDog();
						if (commandAdoption == 2)
						{
							int i = this->ctrl.adoptCurrentDog();
							if (i == 0)
								cout << "cannot adopt once again.\n";
							else
								cout << "added to the adoption list successfully.\n";
							this->ctrl.nextDog();
						}
					}
					break;
				}
				case 4:
				{
					DynamicVector<Dog> v = UI::FilterUI();
					this->ctrl.setDogs(v);
					//seteaza userlist.dogs la cu un alt DA.
					break;
				}

				}
			}
		}
	}
}