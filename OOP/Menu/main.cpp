#include "MenuBar.h"
#include "ExitAction.h"
#include "CreateAction.h"

int main()
{
	MenuBar menuBar;
	Menu fileMenu("File");
		Menu* newMenu = new Menu{ "New" };

			Action* newC = new CreateAction;
			MenuItem* newCItem = new MenuItem{ "C++",newC };
			newMenu->add(newCItem);

			Action* newTextAction = new CreateAction;
			MenuItem* newText = new MenuItem{ "Text",newTextAction };
			newMenu->add(newText);
		fileMenu.add(newMenu);

	Action* exit = new ExitAction;
	MenuItem* exitItem = new MenuItem{ "Exit",exit };
	fileMenu.add(exitItem);

	menuBar.add(fileMenu);

	Menu aboutMenu{ "About" };
	menuBar.add(aboutMenu);

	menuBar.print();
	//newCItem->clicked();
	int ceva;
	std::cin >> ceva;
	return 0;
}