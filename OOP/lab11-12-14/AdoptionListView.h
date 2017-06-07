#ifndef ADOPTIONLISTVIEW_H
#define ADOPTIONLISTVIEW_H

#include <QWidget>
#include "ui_AdoptionListView.h"
#include  "FileUserAdoptionList.h"
#include "PictureDelegate.h"


class AdoptionListView : public QWidget
{
	Q_OBJECT

public:
	AdoptionListView(FileUserAdoptionList *u, QAbstractItemModel*model, QWidget *parent = 0);
	~AdoptionListView();
	void exitHandler();
	void setupPictureTableView();

private:
	Ui::AdoptionListView ui; 
	QAbstractItemModel* tableModel;
	FileUserAdoptionList *user;
};

#endif // ADOPTIONLISTVIEW_H
