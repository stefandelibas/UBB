#include "MyTableModel.h"



#include <qbrush.h>
#include <qcolor.h>


int MyTableModel::rowCount(const QModelIndex & parent) const
{
	return this->user->getDogs().size();
}

int MyTableModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant MyTableModel::data(const QModelIndex & index, int role) const
{
	Dog currentDog = this->user->getDogs()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		// first column - name
			return QString::fromStdString(currentDog.getBreed());
		case 1:		// second column - group
			return QString::fromStdString(currentDog.getName());
		case 2:		// third column - lab grade
			return QString::number(currentDog.getAge());
		case 3:		// fourth column - seminar grade
			return QString::fromStdString(currentDog.getSource());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Breed" };
			case 1:
				return QString{ "Name" };
			case 2:
				return QString{ "Age" };
			case 3:
				return QString{ "Source" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool MyTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Dog& currentDog = this->user->getDogs()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
		{
			std::string labGrade{ value.toString().toStdString() };
			//currentDog.setLabGrade(std::stod(labGrade));
			break;
		}
		case 3:
		{
			std::string seminarGrade{ value.toString().toStdString() };
			//currentStudent.setSeminarGrade(std::stod(seminarGrade));
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}


MyTableModel::~MyTableModel()
{
}
