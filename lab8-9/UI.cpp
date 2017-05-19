#include "UI.h"
#include <string>
#include"Dog.h"
#include <cstdio>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator Mode"<<endl;
	cout << "2 - User mode"<<endl;
	//cout << "3 - number  of instances that have been created since the application was started"<<endl;
	//cout << "4 - the total number of instances" << endl;
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
	cout << "\t 5 - save adoption list to file\n";
	cout << "\t 6 - display adoption list in to file\n";
	cout << "\t 0 - back\n";
}

void UI::printAdoptionMenu()
{
	Dog d = this->ctrl.getUserList()->getCurrentDog();
	cout << "name:" << d.getName()<<" ";
	cout << "breed:" << d.getBreed()<<" ";
	cout << "age:" << d.getAge()<<endl;
	//d.showPhoto();

	cout << "possible commands:" << endl;
	cout << "\t 1 - next dog" << endl;
	cout << "\t 2 - adopt this dog." << endl;
	cout << "\t 0 - exit adoption." << endl;
}
void UI::addDogToRepoUI()
{
	cout << "Enter dog's details." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	if (validator.ValidString(breed))
		throw std::invalid_argument("The breed must be specified");
	cout << "Name:";
	std::string name;
	getline(cin, name);
	if (validator.ValidString(name))
		throw std::invalid_argument("The name must be specified");
	cout << "Age:";
	std::string age_string;
	getline(cin, age_string);
	int age = stoi(age_string);
	if (validator.ValidIntegerNumber(age))
		throw std::invalid_argument("The age must be a number grater than 0");
	cout << "photo source:";
	std::string source;
	getline(cin, source);
	if (validator.ValidString(source))
		throw std::invalid_argument("The source must be specified");
	try
	{
		this->ctrl.addDogToRepository(breed, name, age, source);
	}
	catch (const std::invalid_argument& err)
	{
		throw std::invalid_argument(err);
	}
}


void UI::deleteDogFromRepoUI()
{
	cout << "Enter dog's details." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	if (validator.ValidString(breed))
		throw std::invalid_argument("The breed must be specified");
	cout << "Name:";
	std::string name;
	getline(cin, name);
	if (validator.ValidString(name))
		throw std::invalid_argument("The name must be specified");
	cout << "Age:";
	std::string age_string;
	getline(cin, age_string);
	int age = stoi(age_string);
	if (validator.ValidIntegerNumber(age))
		throw std::invalid_argument("The age must be a number grater than 0");

	try
	{
		this->ctrl.deleteDogFromRepository(breed, name, age);
	}
	catch (const std::invalid_argument& err)
	{
		throw std::invalid_argument(err);
	}
}

void UI::updateDogFromRepoUI()
{
	cout << "Enter the details of the dog you want to update." << endl;
	cout << "Breed:";
	std::string breed;
	getline(cin, breed);
	if (validator.ValidString(breed))
		throw std::invalid_argument("The breed must be specified");
	cout << "Name:";
	std::string name;
	getline(cin, name);
	if (validator.ValidString(name))
		throw std::invalid_argument("The name must be specified");
	cout << "Enter the new details of the dog." << endl;
	cout << "New age:";
	std::string age_string;
	getline(cin, age_string);
	int age=stoi(age_string);
	if(validator.ValidIntegerNumber(age))
		throw std::invalid_argument("The age must be a number grater than 0");
	cout << "New photo source:";
	std::string source;
	getline(cin, source);
	if (validator.ValidString(source))
		throw std::invalid_argument("The source must be specified");
	try
	{
		this->ctrl.updateDogFromRepository(breed, name, age, source);
	}
	catch (const std::invalid_argument& err)
	{
		throw std::invalid_argument(err);
	}

}
void UI::displayAllDogsRepo()
{
	std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
	if (dogs.size() == 0)
	{
		cout << "No dog in the repository." << endl;
		return;
	}
	for (int i = 0; i < dogs.size(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() <<endl;
	}
}

void UI::displayAllDogsAdopted()
{
	std::vector<Dog> dogs = this->ctrl.getUserList()->getDogs();
	if (dogs.size() == 0)
	{
		cout << "No dog in the repository." << endl;
		return;
	}
	for (int i = 0; i < dogs.size(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() << endl;
	}
}
void UI::saveUserAdoptionListToFile()
{
	string filename;
	cout << "Input the filename(absolute path):";
	getline(cin, filename);

	this->ctrl.saveUserAdoiptionList(filename);
	if (this->ctrl.getUserList() == nullptr)
	{
		cout << "Adoption list cannot be displayed\n";
		return;
	}
}
std::vector<Dog> UI::FilterUI()
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

UI::~UI()
{
}

void UI::run(int instances)
{
	int new_instances = 0;

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
					try
					{
						this->addDogToRepoUI();
					}
					catch (const std::invalid_argument& err)
					{
						std::cout << err.what() << '\n';
						break;
					}
					new_instances++;
					instances++;
					cout << "Add successfully done!\n";
					break;
				}
				case 2:
				{
					try
					{
						this->deleteDogFromRepoUI();
					}
					catch (const std::invalid_argument& err)
					{
						std::cout << err.what() << '\n';
						break;
					}
					new_instances--;
					instances--;
					cout << "Delete successfully done!\n";
					break;
				}
				case 3:
				{
					try
					{
						this->updateDogFromRepoUI();
					}
					catch (const std::invalid_argument& err)
					{
						std::cout << err.what() << '\n';
						break;
					}
					cout << "Update successfully done!\n";
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
		if (command == 3)
			cout << "The number of instances were created since the app was started was :" << new_instances;
		if (command == 4)
			cout << "The total number of instances is:" << Dog::getInstances();
	
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
							try
							{
								this->ctrl.adoptCurrentDog();
							}
							catch (const std::invalid_argument& err)
							{
								std::cout << err.what() << '\n';
								break;
							}
							cout << "added to the adoption list successfully.\n";
							this->ctrl.nextDog();
						}
					}
					break;
				}
				case 4:
				{
					std::vector<Dog> v = UI::FilterUI();
					this->ctrl.setDogs(v);
					break;
				}
				case 5:
				{
					this->saveUserAdoptionListToFile();
					break;
				}
				case 6:
				{
					this->ctrl.openUserAdoptionList();
					break;
				}

				}
			}
		}
	}
}