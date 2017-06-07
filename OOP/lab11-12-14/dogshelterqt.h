#ifndef DOGSHELTERQT_H
#define DOGSHELTERQT_H

#include <QtWidgets/QMainWindow>
#include "ui_dogshelterqt.h"
#include "Utils.h"
#include <string>
#include <vector>
#include"Controller.h"
#include "qmessagebox.h"
#include "qcustomplot.h"



class DogShelterQT : public QMainWindow
{
	Q_OBJECT
private:
	Controller &ctrl;
	QCustomPlot *customPlot;
	QAction *openStats;
public:
	DogShelterQT(Controller &c, QWidget *parent = 0);
	int getSelectedIndex();
	void populateTextBoxes();
	void listHandler();
	void removeHandler();
	void updateHandler();
	void addButtonHandler();
	void populateList();
	void connectSignalAndSlots();
	void comboBoxHandler();
	void statisticAges();
	void nextHandler();
	void changeToUserMode();
	void changeToAdminMode();
	void adoptCurrentHandler();
	void filterHandler();
	void adoptAllHandler();
	void saveToFileHandler();
	void popStatDialog();
	void undoHandler();
	~DogShelterQT();

private:
	Ui::DogShelterQTClass ui;
};

#endif // DOGSHELTERQT_H
