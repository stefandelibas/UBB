#include "AdoptionListView.h"

AdoptionListView::AdoptionListView(FileUserAdoptionList *u, QAbstractItemModel* model, QWidget *parent) : QWidget(parent), user{ u }, tableModel{ model }
{
	ui.setupUi(this);

	this->ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.tableView->setModel(this->tableModel);

	this->setupPictureTableView();

	connect(ui.exitButton, &QPushButton::clicked, this, &AdoptionListView::exitHandler);
}

AdoptionListView::~AdoptionListView()
{

}

void AdoptionListView::exitHandler()
{
	this->close();
}

void AdoptionListView::setupPictureTableView()
{
	ui.tableView->setModel(this->tableModel);

	// set the custom delegate
	ui.tableView->setItemDelegate(new PictureDelegate{});

	// force the columns to resize, according to the size of their contents
	ui.tableView->resizeColumnsToContents();
	ui.tableView->resizeRowsToContents();
	// hide the vertical header
	ui.tableView->verticalHeader()->hide();
}
