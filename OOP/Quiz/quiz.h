#ifndef QUIZ_H
#define QUIZ_H

#include <QtWidgets/QMainWindow>
#include "ui_quiz.h"
#include "Controller.h"
#include "Utils.h"

class Quiz : public QMainWindow
{
	Q_OBJECT
private:
	Controller &ctrl;
	Participant participant;
	std::vector<int> answered;
public:
	Quiz(Participant p,Controller &cn,QWidget *parent = 0);
	~Quiz();
	void populateList();
	int getSelectedIndex();
	void submitHandler();
	void listHandler();
	void addQuestion();
private:
	Ui::QuizClass ui;
};

#endif // QUIZ_H
