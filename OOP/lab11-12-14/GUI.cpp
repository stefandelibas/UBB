#include "GUI.h"
#include "qmessagebox.h"


GUI::GUI(Controller & c, Validator valid, QWidget * parent):ctrl{c}
{
	this->setWindow();
	this->populateList();
	this->filterCombo->setCurrentIndex(0);
	connect(this->add, &QPushButton::clicked, this, &GUI::addButtonHandler);
	connect(this->dogsWidgetList, &QListWidget::itemClicked, this, &GUI::listHandler);
	connect(this->remove, &QPushButton::clicked, this, &GUI::removeHandler);
	connect(this->update, &QPushButton::clicked, this, &GUI::updateHandler);
	connect(this->filterCombo, &QComboBox::currentTextChanged, this, &GUI::comboBoxHandler);
	//connect(this->statistic, &QPushButton::clicked, this, &GUI::statsWindow);
	//connect(this->dogsWidgetList, &QListWidget::currentTextChanged, this, &GUI::statisticAges);
}


void GUI::setWindow()
{
	QHBoxLayout* bigLayout = new QHBoxLayout(this);
	QVBoxLayout*mainLayout = new QVBoxLayout(this);
	QVBoxLayout*sideLayout = new QVBoxLayout(this);

	this->statistic = new QPushButton("Age Stats");
	sideLayout->addWidget(statistic);

	this->filterCombo = new QComboBox;
	filterCombo->addItem("Detailed");
	filterCombo->addItem("Short");
	mainLayout->addWidget(this->filterCombo);
	
	this->dogsWidgetList = new QListWidget;
	mainLayout->addWidget(this->dogsWidgetList);
	QHBoxLayout * buttonLayout = new QHBoxLayout;
	
	QFormLayout *formLayout = new QFormLayout{};
	this->breedTextBox = new QLineEdit{};
	QLabel* breedLabel = new QLabel{ "&Breed:" };
	breedLabel->setBuddy(breedTextBox);
	this->nameTextBox = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Name:" };
	nameLabel->setBuddy(nameTextBox);
	this->ageTextBox = new QLineEdit{};
	QLabel* ageLabel = new QLabel{ "&Age:" };
	ageLabel->setBuddy(ageTextBox);
	this->linkTextBox = new QLineEdit{};
	QLabel* linkLabel = new QLabel{ "&Link:" };
	linkLabel->setBuddy(linkTextBox);
	formLayout->addRow(breedLabel, breedTextBox);
	formLayout->addRow(nameLabel, nameTextBox);
	formLayout->addRow(ageLabel, ageTextBox);
	formLayout->addRow(linkLabel, linkTextBox);
	mainLayout->addLayout(formLayout);

	QGridLayout *gridLayout = new QGridLayout{};
	this->add = new QPushButton{ "Add" };
	this->remove = new QPushButton("Remove");
	this->update = new QPushButton("Update");
	gridLayout->addWidget(add, 0, 0);
	gridLayout->addWidget(remove, 0, 1);
	gridLayout->addWidget(update, 0, 2);
	gridLayout->addWidget(new QPushButton("Filter"), 1, 1);
	gridLayout->addWidget(new QPushButton("Sort"),2, 0, 1, 3);
	mainLayout->addLayout(gridLayout);
	bigLayout->addLayout(mainLayout);
	bigLayout->addLayout(sideLayout);

	
}

int GUI::getSelectedIndex()
{
	if(this->dogsWidgetList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->dogsWidgetList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->breedTextBox->clear();
		this->nameTextBox->clear();
		this->ageTextBox->clear();
		this->linkTextBox->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::populateTextBoxes()
{
	int i = this->getSelectedIndex();
	QString dogQ = this->dogsWidgetList->item(i)->text();
	std::string dog = dogQ.toStdString();
	std::vector<std::string> tokens = tokenize(dog, ',');
	this->breedTextBox->setText(QString::fromStdString(tokens[0]));
	if (filterCombo->currentText() == "Detailed")
	{
		this->nameTextBox->setText(QString::fromStdString(tokens[1]));
		this->ageTextBox->setText(QString::fromStdString(tokens[2]));
	}
	else
	{
		this->nameTextBox->clear();
		this->ageTextBox->clear();
	}
	//this->linkTextBox->setText(QString::fromStdString(tokens[3]));
}

void GUI::listHandler()
{
	this->populateTextBoxes();
}

void GUI::removeHandler()
{
	QString breedQ = this->breedTextBox->text();
	QString nameQ = this->nameTextBox->text();
	try
	{
		this->ctrl.deleteDogFromRepository(breedQ.toStdString(), nameQ.toStdString(), 0);
	}
	catch (std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Dog cannot be removed", QMessageBox::Ok);
	}
	this->populateList();

}

void GUI::updateHandler()
{
	
	QString breedQ = this->breedTextBox->text();
	QString nameQ = this->nameTextBox->text();
	QString ageQ = this->ageTextBox->text();
	QString linkQ = this->linkTextBox->text();
	try
	{
		this->ctrl.updateDogFromRepository(breedQ.toStdString(), nameQ.toStdString(), ageQ.toInt(), linkQ.toStdString());
	}
	catch (std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "The dog does not exists.", QMessageBox::Ok);
	}
	this->populateList();
	
}


void GUI::addButtonHandler()
{
	//QMessageBox::critical(nullptr, "Error", "Hello, button add was clicked.", QMessageBox::Ok);
	QString breedQ = this->breedTextBox->text();
	QString nameQ = this->nameTextBox->text();
	QString ageQ = this->ageTextBox->text();
	QString linkQ = this->linkTextBox->text();
	
	try
	{
		this->ctrl.addDogToRepository(breedQ.toStdString(), nameQ.toStdString(), ageQ.toInt(), linkQ.toStdString());
	}
	catch (std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Dog allready exists", QMessageBox::Ok);
	}
	this->populateList();
}



void GUI::populateList()
{
	std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
	this->dogsWidgetList->clear();
	for (auto d : dogs)
	{
		QString breedQ = QString::fromStdString(d.getBreed());
		QString nameQ = QString::fromStdString(d.getName());
		QString ageQ = QString::fromStdString(std::to_string(d.getAge()));
		QString dog = breedQ + "," + nameQ + "," + ageQ;
		this->dogsWidgetList->addItem(dog);
	}
}

void GUI::comboBoxHandler()
{
	if (this->filterCombo->currentText() == "Short")
	{
		std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
		this->dogsWidgetList->clear();
		for (auto d : dogs)
		{
			QString nameQ = QString::fromStdString(d.getName());
			QString dog = nameQ;
			this->dogsWidgetList->addItem(dog);
		}
	}
	else
		this->populateList();
}

void GUI::statisticAges()
{
	std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
	std::vector<int> ages{ 0,0,0,0,0,0,0,0,0,0,0,0 };
	for (auto d : dogs)
	{
		ages[d.getAge()]++;
	}	

	this->customPlot = new QCustomPlot;
	customPlot->addGraph();
	QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	myBars->setName("Bars Series 1");
	QVector<double> keyData;
	QVector<double> valueData;
	customPlot->xAxis->setRange(0,10);
	keyData << 0 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
	valueData << ages[0] << ages[1] << ages[2] << ages[3] << ages[4] << ages[5] << ages[6] << ages[7] << ages[8] << ages[9] << ages[10];
	myBars->setData(keyData, valueData);
	myBars->setWidth(1);
	customPlot->xAxis->setScaleRatio(customPlot->xAxis,1);
	customPlot->yAxis->setScaleRatio(customPlot->yAxis, 1);

	customPlot->rescaleAxes();
	customPlot->resize(100, 100);
	customPlot->replot();

}

void GUI::statsWindow()
{
	QWidget *statWindow = new QWidget;
	QVBoxLayout*theLayout = new QVBoxLayout(statWindow);
	theLayout->addWidget(customPlot);
	this->statisticAges();
	theLayout->addWidget(customPlot);
	statWindow->show();
}

GUI::~GUI()
{
}
