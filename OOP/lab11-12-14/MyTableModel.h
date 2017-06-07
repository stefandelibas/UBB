#pragma once
#include <qabstractitemmodel.h>
#include "FileUserAdoptionList.h"

class MyTableModel : public QAbstractTableModel
{
private:
	FileUserAdoptionList *user;
public:
	~MyTableModel();
	MyTableModel(FileUserAdoptionList *u) : user{ u } {}

	// we must implement the following three methods (which are abstract in the class QAbstractTableModel)
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;							// provides the number of rows for the table
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;						// provides the number of columns for the table
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;				// provides the text content for a cell

																									// add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;	// will be called when a cell is edited
	Qt::ItemFlags flags(const QModelIndex & index) const override;
};

