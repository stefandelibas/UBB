#include "PictureDelegate.h"
#include<qpixmap.h>
#include<qpainter.h>
#include "Dog.h"



PictureDelegate::~PictureDelegate()
{
}



void PictureDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString dog = index.model()->data(index, Qt::EditRole).toString();

	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() != 0)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	if (dog.contains("Samoyed"))
	{
		QPixmap pixMap("samoyed.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Akita"))
	{
		QPixmap pixMap("akita.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Beagle"))
	{
		QPixmap pixMap("beagle.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Doberman"))
	{
		QPixmap pixMap("doberman.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Berna"))
	{
		QPixmap pixMap("berna.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Retriver"))
	{
		QPixmap pixMap("retriver.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Sharpei"))
	{
		QPixmap pixMap("sharpei.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Labrador"))
	{
		QPixmap pixMap("labrador.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (dog.contains("Chihuahua"))
	{
		QPixmap pixMap("chihuahua.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() == 1)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}