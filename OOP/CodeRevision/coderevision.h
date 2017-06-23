#ifndef CODEREVISION_H
#define CODEREVISION_H

#include <QtWidgets/QMainWindow>
#include "ui_coderevision.h"
#include "Controller.h"
#include "Programmer.h"

class CodeRevision : public QMainWindow
{
	Q_OBJECT
private:
	std::string programmerName;
	Controller ctrl;
	std::vector<CodeRevision*>& windows;
public:
	CodeRevision(std::string &p,Controller &c, std::vector<CodeRevision*>& win, QWidget *parent = 0);
	~CodeRevision();
	void populateList();
	int getSelectedIndex();
	void reviseHandler();
	void listHandler();
	void addHandler();

private:
	Ui::CodeRevisionClass ui;
};

#endif // CODEREVISION_H
