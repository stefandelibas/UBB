#include "UI.h"
#include <iostream>


using namespace std;

UI::UI()
{
}

void UI::printMenu()
{
	cout << "1 - display all\n";
	cout << "2 - add project\n";
	cout << "3 - mark a project as done"<<endl;
	cout << "4 - change price"<<endl;
	cout << "5 - filter date" << endl;
	cout << "0 - to exit\n";
}

int UI::addMenu()
{
	cout << "Name:";
	std::string name;
	getline(cin, name);
	cout << "Customer:";
	std::string customer;
	getline(cin, customer);
	cout << "Date:";
	std::string date;
	getline(cin, date);
	cout << "Price:";
	double price;
	cin >> price;
	cin.ignore();
	cout << "isDone(1 or 0):";
	int i;
	bool isDone;
	cin >> i;
	if (i == 1)
		isDone = true;
	else
		isDone = false;

	return this->ctrl.addToRepository(name, customer, date, price, isDone);
}

void UI::displayAllUI()
{
	DynamicVector<Project> projects = this->ctrl.getRepo().getProjects();
	if (projects.getSize() == 0)
	{
		cout << "there is no project in the repository\n";
		return;
	}
	for (int i = 0; i < projects.getSize(); i++)
	{
		Project p = projects[i];
		cout << "Name:" << p.getName() << " Cusotmer:" << p.getCustomer() << " Date:" << p.getDate() << " Price:" << p.getPrice();
		if (p.getIsDone())
			cout << " Done\n";
		else
			cout << " Not Done Yet.\n";
	}
}

int  UI::markAsDoneUI()
{
	cout << "Name:";
	std::string name;
	getline(cin, name);
	cout << "\nCustomer:";
	std::string customer;
	getline(cin, customer);

	return this->ctrl.markAsDone(name, customer);
	
}

int UI::setPriceUI()
{
	cout << "Name:" << endl;
	std::string name;
	getline(cin, name);
	cout << "Customer: " << endl;
	std::string customer;
	getline(cin, customer);
	cout << "The price you want to set: " << endl;
	double price;
	cin >> price;
	cin.ignore();
	return this->ctrl.changePrice(name, customer, price);
}

void UI::filterDate()
{
	cout << "Input the date:" << endl;
	std::string date;
	getline(cin, date);
	DynamicVector<Project> v=this->ctrl.filterDateCtrl(date);
	if (v.getSize() == 0)
		cout << "There are no projects mathing the criteria\n";
	for (int i = 0; i < v.getSize(); i++)
	{
		Project p = v[i];
		cout << "Name:" << p.getName() << " Cusotmer:" << p.getCustomer() << " Date:" << p.getDate() << " Price:" << p.getPrice();
		if (p.getIsDone())
			cout << " Done\n";
		else
			cout << " Not Done Yet.\n";		
	}
}

void UI::runUI()
{
	while (true)
	{
		this->printMenu();
		int command;
		cout << "input your command:";
		cin >> command;
		cin.ignore();
	
		if (command == 0)
			break;
		if (command == 1)
			this->displayAllUI();
		if (command == 2)
		{
			int i = this->addMenu();
			if (i)
				cout << "Successfully added\n";
			else
				cout << "Couldn't add\n";
		}
		if (command == 3)
		{
			int i = this->markAsDoneUI();
			if (i == 1)
				cout << "The project is marked as done\n";
			else
				if (i == -1)
					cout << "The project was already marked as done\n";
				else
					cout << "Couldn't find the project\n";
		}
		if (command == 4)
		{
			int i = this->setPriceUI();
			if (i)
				cout << "price successfully changed\n";
			else
				cout << "couldn't find the project";
		}
		if (command == 5)
		{
			this->filterDate();
		}

	}
}


UI::~UI()
{
}
