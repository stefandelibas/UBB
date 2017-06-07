#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <QWidget>
#include <qdialog.h>
#include "ui_userchoice.h"

class UserChoice : public QDialog
{
	Q_OBJECT
private:
	int choice;

public:
	UserChoice(QWidget *parent = 0);
	int getChoice();
	void radioButtonHandler();
	void buttonHandler();
	~UserChoice();

private:
	Ui::UserChoice ui;
};

#endif // USERCHOICE_H
