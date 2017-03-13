#include "ui.h"
#include <stdio.h>

/*
creates a controller object, allocating memory and initializing the controller
input:	r - a controller object
*/
UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

/*
destroy a UI object, by destroying the controller and
deallocating  memory occupied by the UI object until now.
*/
void destroyUI(UI * ui)
{
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}

/*
Prints the available menu for the problem
Input : -
Output : the menu is printed at the console
*/
void printMenu()
{
	printf("\n");
	printf("1 - to add a medication. \n");
	printf("2 - to delete a medication.\n");
	printf("3 - to update a medication.\n");
	printf("4 - to show all medications.\n");
	printf("5 - to show all medications containing a given string. \n");
	printf("6 - to show all medications in short supply. \n");
	printf("0 - to exit.\n");
}
/*
Reads an integer number from the keyboard. Asks for number while read errors encoutered.
Input: the message to be displayed when asking the user for input.
Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
/*
check if the command is a valid number(available in the menu list)
input: a number which represents the command
output: 1 - if the command is valid
		0 - if the command is not valid
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 6)
		return 1;
	return 0;
}
/*
reads the input of a new medicine(name, concentration, quantity, price) and passes the data to the controller
input: the ui structure, containing the controller
output: 1 - the medicine was not in the repositry => it was added successfully
		0 - if the medicine was already in the repository => the quantity was increased
*/
int addMedicineUI(UI* ui)
{
	char name[40];
	int quantity;
	float concentration, price;

	printf("\nmedication name:");
	scanf("%s", name);
	printf("concentration:");
	scanf("%f", &concentration);
	printf("quantity:");
	scanf("%d", &quantity);
	printf("pirce:");
	scanf("%f", &price);
	
	return addMedicine(ui->ctrl, name, concentration, quantity, price);
}

/*
reads the input of a medicine(name, concentration, quantity, price) and passes the data to the controller
input: the controller structure, containing the repository, and data for a medicine
		(name, concentration, quantity, price).
output: 1 - the medicine was not in the repositry => error, cannot update an
			object which is not in the repository.
		0 - if the medicine was already in the repository => the object was updated successfully.
*/
int updateMedicineUI(UI* ui)
{
	char name[40];
	int quantity;
	float concentration, price;

	printf("medication name:");
	scanf("%s", name);
	printf("\nconcentration:");
	scanf("%f", &concentration);
	printf("\nnow insert some new data to update your medication.");
	printf("\nquantity:");
	scanf("%d", &quantity);
	printf("\npirce:");
	scanf("%f", &price);
	return updateMedicine(ui->ctrl, name, quantity, concentration, price);
	
}

/*
reads the unique keys of a medicine(name, concentration) and passes them to the controller
input: the controller structure, containing the repository, and unique keys of a medicine
		(name, concentration).
		output: 1 - the medicine was not in the repositry => cannot delete an
		object which is not in the repository.
		0 - if the medicine was already in the repository =>  the object was deleted successfully
*/
int deleteMedicineUI(UI* ui)
{
	char name[40];
	float concentration;
	printf("medication name:");
	scanf("%s", name);
	printf("\nconcentration:");
	scanf("%f", &concentration);
	return deleteMedicine(ui->ctrl, name, concentration);
}

/*
takes the data from the controller and prints all medicines on the screen
input:	ui - ui object
output:	-
*/
void listAllMedicines(UI *ui)
{
	MedRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored medicines.";
		printf("%s \n", str);
	}
	
	int i;
	for (i = 0; i < length; i++)
	{
		char str[256];
		toString(getMedicineAtX(repo, i), str);
		printf("%s\n", str);
	}
}

/*
reads a string, takes the data from the controller and prints on the screen 
the medicines containing the given string 
input:	ui - ui object
output:	a repository object containing the medicines after filtering them
		or the whole repository if the string was 'null'
*/
void listMedicineContainingXUI(UI* ui)
{
	char x[20];
	int way, record;
	printf("\nInsert a string:");
	scanf("%s", x);
	way = readIntegerNumber("\n1 - for ascending order\n2 - for descending order\nyour choice:");
	record = readIntegerNumber("\n1 - filter by name\n2 - filter by price\nyour choice:");
	MedRepo* repo = filter(ui->ctrl, x, way, record);
	int i, length = getLength(repo);
	for (i = 0; i < length; i++)
	{
		char str[256];
		toString(getMedicineAtX(repo, i), str);
		printf("%s\n", str);
	}
}
void listLessSpulyUI(UI* ui)
{
	int way, q;
	way = readIntegerNumber("\nsort:\n1 - for ascending order\n2 - for descending order\nyour choice:");
	q = readIntegerNumber("\nthe most quantity:");
	MedRepo* repo = filterByQuantity(ui->ctrl, way, q);
	int i, length = getLength(repo);
	for (i = 0; i < length; i++)
	{
		char str[256];
		toString(getMedicineAtX(repo, i), str);
		printf("%s\n", str);
	}
}
void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;

		switch (command)
		{
		case 1:
		{
			int res = addMedicineUI(ui);
			if (res == 1)
				printf("Medicine succesfully added.\n");
			else
				printf("Medicine quantity added.");
			break;
		}
		case 2:
		{
			int res = deleteMedicineUI(ui);
			if (res == 1)
				printf("Medicine succesfully deleted.\n");
			else
				printf("Medicine not found.");
			break;
		}
		case 3:
		{
			int res = updateMedicineUI(ui);
			if (res == 1)
				printf("Medicine succesfully updated.\n");
			else
				printf("Medicine not found.");
			break;
		}
		case 4:
		{
			listAllMedicines(ui);
			break;
		}
		case 5:
		{
			listMedicineContainingXUI(ui);
			break;
		}
		case 6:
		{
			listLessSpulyUI(ui);
			break;
		}

		}
	}

}


