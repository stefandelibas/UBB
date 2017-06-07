#include "dogshelterqt.h"
#include "AdoptionListView.h"
#include "MyTableModel.h"

DogShelterQT::DogShelterQT(Controller &c,QWidget *parent) : QMainWindow(parent), ctrl{ c }
{
	ui.setupUi(this);
	//this->openStats->setObjectName("Statistics");
	//ui.menuMain->addAction("Stats","Stats",);
	//statisticAges();
	/*
	QVBoxLayout *s = new QVBoxLayout;
	QRect r;
	r.setHeight(500);
	r.setWidth(500);
	s->setGeometry(r);
	s->addWidget(customPlot);
	ui.leftLayout->addLayout(s);
	*/
	//ui.leftLayout->addWidget(customPlot);
	this->connectSignalAndSlots();
	this->populateList();
}

int DogShelterQT::getSelectedIndex()
{
	if (ui.dogListWidget->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = ui.dogListWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		ui.breedLineEdit->clear();
		ui.nameLineEdit->clear();
		ui.ageLineEdit->clear();
		ui.linkLineEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void DogShelterQT::populateTextBoxes()
{
	int i = this->getSelectedIndex();
	QString dogQ = ui.dogListWidget->item(i)->text();
	std::string dog = dogQ.toStdString();
	std::vector<std::string> tokens = tokenize(dog, ',');
	ui.breedLineEdit->setText(QString::fromStdString(tokens[0]));
	if (ui.filterCombo->currentText() == "Detailed")
	{
		ui.nameLineEdit->setText(QString::fromStdString(tokens[1]));
		ui.ageLineEdit->setText(QString::fromStdString(tokens[2]));
	}
	else
	{
		ui.nameLineEdit->clear();
		ui.ageLineEdit->clear();
	}
	//this->linkTextBox->setText(QString::fromStdString(tokens[3]));
}

void DogShelterQT::listHandler()
{
	this->populateTextBoxes();
}

void DogShelterQT::removeHandler()
{
	QString breedQ = ui.breedLineEdit->text();
	QString nameQ = ui.nameLineEdit->text();
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

void DogShelterQT::updateHandler()
{

	QString breedQ = ui.breedLineEdit->text();
	QString nameQ = ui.nameLineEdit->text();
	QString ageQ = ui.ageLineEdit->text();
	QString linkQ = ui.linkLineEdit->text();
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


void DogShelterQT::addButtonHandler()
{
	QString breedQ = ui.breedLineEdit->text();
	QString nameQ = ui.nameLineEdit->text();
	QString ageQ = ui.ageLineEdit->text();
	QString linkQ = ui.linkLineEdit->text();
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



void DogShelterQT::populateList()
{
	std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
	ui.dogListWidget->clear();
	for (auto d : dogs)
	{
		QString breedQ = QString::fromStdString(d.getBreed());
		QString nameQ = QString::fromStdString(d.getName());
		QString ageQ = QString::fromStdString(std::to_string(d.getAge()));
		QString dog = breedQ + "," + nameQ + "," + ageQ;
		ui.dogListWidget->addItem(dog);
	}
}
void DogShelterQT::comboBoxHandler()
{
	if (ui.filterCombo->currentText() == "Short")
	{
		std::vector<Dog> dogs = this->ctrl.getRepo().getDogs();
		ui.dogListWidget->clear();
		for (auto d : dogs)
		{
			QString nameQ = QString::fromStdString(d.getName());
			QString dog = nameQ;
			ui.dogListWidget->addItem(dog);
		}
	}
	else
		this->populateList();
}

void DogShelterQT::statisticAges()
{
	std::vector<Dog> dogs = ctrl.getRepo().getDogs();
	std::vector<int> ages{ 0,0,0,0,0,0,0,0,0,0,0,0 };
	for (auto d : dogs)
	{
		ages[d.getAge()]++;
	}

	customPlot = new QCustomPlot;
	customPlot->addGraph();
	QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	myBars->setName("Bars Series 1");
	QVector<double> keyData;
	QVector<double> valueData;
	customPlot->xAxis->setRange(0, 10);
	keyData << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
	valueData << ages[0] << ages[1] << ages[2] << ages[3] << ages[4] << ages[5] << ages[6] << ages[7] << ages[8] << ages[9] << ages[10];
	myBars->setData(keyData, valueData);
	myBars->setWidth(1);
	//customPlot->xAxis->setScaleRatio(customPlot->xAxis, 1);
	//customPlot->yAxis->setScaleRatio(customPlot->yAxis, 5);
	//customPlot->yAxis->setPadding(5);
	//customPlot->yAxis->rescale();
	customPlot->rescaleAxes();
	customPlot->resize(1000, 1000);
	customPlot->replot();

}

void DogShelterQT::nextHandler()
{
	ctrl.nextDog();
	Dog d = ctrl.getUserList()->getCurrentDog();
	QString breedQ = QString::fromStdString(d.getBreed());
	QString nameQ = QString::fromStdString(d.getName());
	QString ageQ = QString::fromStdString(std::to_string(d.getAge()));
	QString dog = breedQ + "," + nameQ + "," + ageQ;
	ui.nextDogLineEdit->setText(dog);
}

void DogShelterQT::changeToUserMode()
{
	Dog d = ctrl.getUserList()->getCurrentDog();
	QString breedQ = QString::fromStdString(d.getBreed());
	QString nameQ = QString::fromStdString(d.getName());
	QString ageQ = QString::fromStdString(std::to_string(d.getAge()));
	QString dog = breedQ + "," + nameQ + "," + ageQ;
	ui.nextDogLineEdit->setText(dog);
	ctrl.setDogs(ctrl.getRepo().getDogs());
	//disable admin mode
}

void DogShelterQT::changeToAdminMode()
{
	ui.nextDogLineEdit->clear();
	MyTableModel *tabelModel = new MyTableModel{ this->ctrl.getUserList() };
	AdoptionListView *newAdoptionView = new AdoptionListView{this->ctrl.getUserList(),tabelModel,this};
	newAdoptionView->show();
	//disable user actions
}

void DogShelterQT::adoptCurrentHandler()
{
	
	QString dogQ = ui.nextDogLineEdit->text();
	try
	{
		this->ctrl.adoptCurrentDog();
		ui.adoptedListWidget->addItem(dogQ);
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "The dog already in the adoption list.", QMessageBox::Ok);
	}
	this->ctrl.nextDog();
}

void DogShelterQT::filterHandler()
{
	QString ageQ = ui.ageLineEditFilter->text();
	if (ageQ == "")
	{
		std::vector<Dog> aux = ctrl.getRepo().getDogs();
		ctrl.setDogs(aux);
		//QMessageBox::critical(nullptr, "Error", "The dog already in the adoption list.", QMessageBox::Ok);
		return;
	}
	int age = ageQ.toInt();
	QString breedQ = ui.breedLineEditFilter->text();
	if (breedQ == "")
	{
		std::vector<Dog> aux = ctrl.filterController(age);
		ctrl.setDogs(aux);
	}
	else
	{
		std::string breed = breedQ.toStdString();
		std::vector<Dog> aux = ctrl.filterController(breed, age);
		ctrl.setDogs(aux);
	}
}

void DogShelterQT::adoptAllHandler()
{
	for (int i = 0; i < ui.adoptedListWidget->count(); i++)
	{
		QString dogQ = ui.adoptedListWidget->item(i)->text();
		std::string dog = dogQ.toStdString();
		std::vector<std::string> tokens = tokenize(dog, ',');
		std::string breed = tokens[0];
		std::string name = tokens[1];
		int age = std::stoi(tokens[2]);
		ctrl.deleteDogFromRepository(breed, name, age);
	}
	populateList();
}

void DogShelterQT::saveToFileHandler()
{
	QString fileQ = ui.fileNameLineEdit->text();
	std::string filename = fileQ.toStdString();
	this->ctrl.saveUserAdoiptionList(filename);
	if (this->ctrl.getUserList() == nullptr)
	{
		std::cout << "Adoption list cannot be displayed\n";
		return;
	}
}

void DogShelterQT::popStatDialog()
{
	QWidget *s = new QWidget();
	//ui.menuStatistics->addMenu("Statistics");
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	statisticAges();
	mainLayout->addWidget(customPlot);
	s->setLayout(mainLayout);
	s->show();
}

void DogShelterQT::undoHandler()
{
	try
	{
		ctrl.ExecUndo();
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Could not do undo", QMessageBox::Ok);
	}
	populateList();
}

void DogShelterQT::connectSignalAndSlots()
{
	connect(ui.addButton, &QPushButton::clicked, this, &DogShelterQT::addButtonHandler);
	connect(ui.dogListWidget, &QListWidget::itemClicked, this, &DogShelterQT::listHandler);
	connect(ui.removeButton, &QPushButton::clicked, this, &DogShelterQT::removeHandler);
	connect(ui.updateButton, &QPushButton::clicked, this, &DogShelterQT::updateHandler);
	connect(ui.filterCombo, &QComboBox::currentTextChanged, this, &DogShelterQT::comboBoxHandler);
	connect(ui.nextButton, &QPushButton::clicked, this, &DogShelterQT::nextHandler);
	connect(ui.toUserMode, &QPushButton::clicked, this, &DogShelterQT::changeToUserMode);
	connect(ui.toAdminMode, &QPushButton::clicked, this, &DogShelterQT::changeToAdminMode);
	connect(ui.adoptCurrent, &QPushButton::clicked, this, &DogShelterQT::adoptCurrentHandler);
	connect(ui.filterButton, &QPushButton::clicked, this, &DogShelterQT::filterHandler);
	connect(ui.adoptAll, &QPushButton::clicked, this, &DogShelterQT::adoptAllHandler);
	connect(ui.savetoFileButton, &QPushButton::clicked, this, &DogShelterQT::saveToFileHandler);
	connect(ui.statButton, &QPushButton::clicked, this, &DogShelterQT::popStatDialog);
	connect(ui.undoButton, &QPushButton::clicked, this, &DogShelterQT::undoHandler);
	//connect(ui.menuMain, &QMenu::triggered, this, &DogShelterQT::popStatDialog);
}

DogShelterQT::~DogShelterQT()
{

}

