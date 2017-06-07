#include "userchoice.h"

UserChoice::UserChoice(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &UserChoice::buttonHandler);
}

int UserChoice::getChoice()
{
	return choice;
}

void UserChoice::buttonHandler()
{
	if (ui.csvRadioButton->isChecked() == true)
	{
		choice = 1;
	}
	else
		if (ui.htmlRadioButton->isChecked() == true) 
		{
			choice = 0;
		}
	
	this->close();
}

UserChoice::~UserChoice()
{

}
