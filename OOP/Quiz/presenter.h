#ifndef PRESENTER_H
#define PRESENTER_H

#include <QWidget>
#include "ui_presenter.h"
#include "Controller.h"
#include "quiz.h"

class presenter : public QWidget
{
	Q_OBJECT
private:
	Controller &ctrl;
	std::vector<Quiz*>& windows;

public:
	presenter(Controller &c, std::vector<Quiz*>& win, QWidget *parent = 0);
	~presenter();
	void populateList();
	void addHandler();


private:
	Ui::presenter ui;
};

#endif // PRESENTER_H
