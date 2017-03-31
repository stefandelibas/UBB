#include "UI.h"
#include <string>

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

}

void UI::addDogToRepoUI()
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

	this->ctrl.addDogToRepository(breed, name, age, source);
}


void UI::deleteDogFromRepoUI()
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

	this->ctrl.deleteDogFromRepository(breed, name, age);
}

void UI::updateDogFromRepoUI()
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

	this->ctrl.updateDogFromRepository(breed, name, age, source);
}
void UI::displayAllDogsRepo()
{
	DynamicVector v = this->ctrl.getRepo().getDogs();
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
				switch(commandAdmin)
				{
					case 1:
					{
						this->addDogToRepoUI();
						break;
					}
					case 2:
					{
						this->deleteDogFromRepoUI();
						break;
					}
					case 3:
					{
						this->updateDogFromRepoUI();
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
				break;
			}
		}


	}
}