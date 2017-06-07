#pragma once
#include "Controller.h"
#include "Validator.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QFormLayout>
#include "Utils.h"
#include <string>
#include <vector>
#include <QComboBox>
#include <QTabWidget>
#include "qcustomplot.h"



class GUI : public QWidget
{
	Q_OBJECT
private:
	Controller &ctrl;
	Validator valid;
	QListWidget* dogsWidgetList;
	QPushButton* add;
	QPushButton* remove;
	QPushButton* update;
	QComboBox* filterCombo;
	QLineEdit* breedTextBox;
	QLineEdit* nameTextBox;
	QLineEdit* ageTextBox;
	QLineEdit* linkTextBox;
	QCustomPlot *customPlot;
	QPushButton*statistic;

public:
	GUI(Controller &c, Validator valid, QWidget *parent = 0);
	void setWindow();
	int getSelectedIndex();
	void populateTextBoxes();
	void listHandler();
	void removeHandler();
	void updateHandler();
	void addButtonHandler();
	void populateList();
	void comboBoxHandler();
	void statisticAges();
	void statsWindow();
	~GUI();
};

