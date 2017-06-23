#include "coderevision.h"
#include "qmessagebox.h"
#include "Utils.h"


CodeRevision::CodeRevision(std::string &p, Controller &c, std::vector<CodeRevision*>& win,QWidget *parent)
	: programmerName{p}, ctrl{ c }, windows{ win }, QMainWindow(parent)
{
	ui.setupUi(this);
	populateList();
	connect(ui.reviseButton, &QPushButton::clicked, this, &CodeRevision::reviseHandler);
	connect(ui.listWidget, &QListWidget::itemClicked, this, &CodeRevision::listHandler);
	//connect(this, &QWidget::closeEvent , this, &CodeRevision::ctrl.storeSourceFile);
	connect(ui.addButton, &QPushButton::clicked, this, &CodeRevision::addHandler);
}

CodeRevision::~CodeRevision()
{
}

int CodeRevision::getSelectedIndex()
{
	if (ui.listWidget->count() == 0)
		return -1;
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

void CodeRevision::reviseHandler()
{
	int i = this->getSelectedIndex();
	QString sourceQ = ui.listWidget->item(i)->text();
	std::string line = sourceQ.toStdString();
	std::vector<std::string> tokens = tokenize(line, ';');

	this->ctrl.revise(tokens[0], this->programmerName);

	for (auto w : this->windows)
	{
		w->populateList();
	}
	int toRevise = ctrl.getToRevise(this->programmerName);
	if (toRevise == 0)
	{
		QMessageBox::information(nullptr, "You're DONE!", "Congratulations!", QMessageBox::Ok);
		this->close();
	}
}

void CodeRevision::listHandler()
{
	int i = this->getSelectedIndex();
	QString sourceQ = ui.listWidget->item(i)->text();
	std::string line = sourceQ.toStdString();
	std::vector<std::string> tokens = tokenize(line, ';');
	if ( tokens[1] == "revised")
	{
		ui.reviseButton->setEnabled(false);
	}
	else
		ui.reviseButton->setEnabled(true);
}

void CodeRevision::addHandler()
{
	QString fileNameQ = ui.fileNameLineEdit->text();
	if (fileNameQ != "")
	{
		std::string fileName = fileNameQ.toStdString();
		try
		{
			ctrl.addSource(fileName, this->programmerName);
			for (auto w : this->windows)
			{
				w->populateList();
			}
		}
		catch (std::exception &err)
		{
			QString e = QString::fromStdString(err.what());
			QMessageBox::critical(nullptr, "Error", e, QMessageBox::Ok);
		}

	}
	else
		QMessageBox::critical(nullptr, "Error", "FileName cannot be blank", QMessageBox::Ok);

}

void CodeRevision::populateList()
{
	std::vector<SourceFile> sources = this->ctrl.getRepo().getSourceFiles();
	ui.listWidget->clear();
	int toRevise = ctrl.getToRevise(this->programmerName);
	int revised = ctrl.getRevised(this->programmerName);
	ui.toReviseLabel->setText(QString::fromStdString(std::to_string(toRevise)));
	ui.revisedLabel->setText(QString::fromStdString(std::to_string(revised)));
	for (auto s : sources)
	{
		QString nameQ = QString::fromStdString(s.getName());
		QString statusQ = QString::fromStdString(s.getStatus());
		QString creatorQ = QString::fromStdString(s.getCreator());
		QString reviewerQ = QString::fromStdString(s.getReviewer());
		QString source = nameQ + ";" + statusQ + ";" + creatorQ + ";" + reviewerQ ;

		if (s.getStatus() == "revised")
		{
			QColor color = QString::fromStdString("green");
			QListWidgetItem* item = new QListWidgetItem{ source };
			item->setForeground(color);
			QFont font;
			font.setBold(true);
			item->setFont(font);
			ui.listWidget->addItem(item);
		}
		else
		{
			ui.listWidget->addItem(source);
		}
		
	}
}
