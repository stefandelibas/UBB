#include "dogshelterqt.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include "Controller.h"
#include "Validator.h"
#include "Repository.h"
#include "FileUserAdoptionList.h"
#include "csvUserAdoptionList.h"
#include "GUI.h"
#include "userchoice.h"
#include "HTMLUserAdoptionList.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "dogs.txt" };
	FileUserAdoptionList* adoptionList{};
	UserChoice u{};
	u.exec();
	int c = u.getChoice();
	if (c == 0)
	{
		adoptionList = new HTMLUserAdoptionList{};
	}
	else
	{
		adoptionList = new csvUserAdoptionList{};
	}
	Controller ctrl{ repo ,adoptionList };
	Validator valid;
	//GUI g{ ctrl,valid };
	DogShelterQT w{ ctrl };
	w.show();
	a.exec();
}
