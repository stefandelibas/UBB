#include "presenter.h"
#include "qmessagebox.h"

presenter::presenter(Controller &c, std::vector<Quiz*>& win,QWidget *parent)
	: ctrl{ c }, windows{ win }, QWidget(parent)
{
	ui.setupUi(this);
	this->populateList();
	connect(ui.pushButton, &QPushButton::clicked, this, &presenter::addHandler);
}
void presenter::populateList()
{
	std::vector<Question> questions = this->ctrl.getRepo().getQuestions();
	ui.questionListWidget->clear();
	for (auto q : questions)
	{
		QString idQ = QString::fromStdString(std::to_string(q.getID()));
		QString textQ = QString::fromStdString(q.getText());
		QString answerQ = QString::fromStdString(q.getAnswer());
		QString scoreQ = QString::fromStdString(std::to_string(q.getScore()));
		QString question = idQ + ";" + textQ + ";" + answerQ + ";" + scoreQ;
		ui.questionListWidget->addItem(question);
	}
}
void presenter::addHandler()
{
	QString idQ = ui.idLineEdit->text();
	QString textQ = ui.textLineEdit->text();
	QString answerQ = ui.answerLineEdit->text();
	QString scoreQ = ui.scoreLineEdit->text();
	if (idQ != "" && textQ != "" &&  answerQ != "" && scoreQ != "")
	{
		try
		{
			this->ctrl.addQuestion(stoi(idQ.toStdString()), textQ.toStdString(), answerQ.toStdString(), stoi(scoreQ.toStdString()));
			for (auto w : this->windows)
			{
				w->addQuestion();
				w->populateList();
			}
			this->populateList();
		}
		catch (std::invalid_argument &err)
		{
			QMessageBox::critical(nullptr, "Error", "Cannot add this question. Invalid ID!", QMessageBox::Ok);
		}
	}
	else
		QMessageBox::critical(nullptr, "Error", "fields cannot be blank", QMessageBox::Ok);
}
presenter::~presenter()
{
	this->ctrl.storeToFile();
}
