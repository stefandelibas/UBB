#include "quiz.h"
#include "qmessagebox.h"

Quiz::Quiz(Participant p, Controller &c,QWidget *parent)
	: participant{ p }, ctrl{ c }, QMainWindow(parent)
{
	ui.setupUi(this);
	std::vector<Question> questions = this->ctrl.getRepo().getQuestions();
	for (auto q : questions)
	{
		this->answered.push_back(0);
	}
	this->populateList();
	connect(ui.submitButton, &QPushButton::clicked, this, &Quiz::submitHandler);
	connect(ui.questionsListWidget, &QListWidget::itemClicked, this, &Quiz::listHandler);
	ui.lineEdit->setDisabled(true);
}
int Quiz::getSelectedIndex()
{
	if (ui.questionsListWidget->count() == 0)
		return -1;
	QModelIndexList index = ui.questionsListWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

void Quiz::submitHandler()
{
	QString answerQ = ui.answerLineEdit->text();
	if (answerQ != "")
	{
		int i = this->getSelectedIndex();
		QString lineQ = ui.questionsListWidget->item(i)->text();
		std::string line = lineQ.toStdString();
		std::vector<std::string> tokens = tokenize(line, ')');
		this->answered[i] = 1;
		std::string correctAnswer = ctrl.getCorrectAnswer(stoi(tokens[0]));
		if (answerQ.toStdString() == correctAnswer)
		{
			ctrl.increaseScore(this->participant.getName(),stoi(tokens[0]));
		}
		this->populateList();
		int score = ctrl.getScore(this->participant.getName());
		ui.lineEdit->setText(QString::fromStdString(std::to_string(score)));
	}
	else
		QMessageBox::critical(nullptr, "Error", "Answer cannot be blank", QMessageBox::Ok);
}

void Quiz::listHandler()
{
	int i = this->getSelectedIndex();
	if (answered[i] == 1)
	{
		ui.submitButton->setEnabled(false);
	}
	else
		ui.submitButton->setEnabled(true);
}

void Quiz::addQuestion()
{
	this->answered.push_back(0);
}

void Quiz::populateList()
{
	std::vector<Question> questions = this->ctrl.getRepo().getQuestions();
	ui.questionsListWidget->clear();
	int i = 0;
	for (auto q : questions)
	{
		QString idQ = QString::fromStdString(std::to_string(q.getID()));
		QString textQ = QString::fromStdString(q.getText());
		QString question = idQ + ")" + textQ;
		
		if (this->answered[i] == 1)
		{
			QColor color = QString::fromStdString("green");
			QListWidgetItem* item = new QListWidgetItem{ question };
			item->setBackgroundColor(color);
			ui.questionsListWidget->addItem(item);
		}
		else
		{
			ui.questionsListWidget->addItem(question);
		}
		i++;
	}
}
Quiz::~Quiz()
{

}
