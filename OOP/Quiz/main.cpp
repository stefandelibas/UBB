#include "quiz.h"
#include "presenter.h"
#include "Repository.h"
#include "Controller.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{"C:\\Users\\Stefan\\Documents\\Visual Studio 2015\\Projects\\Quiz\\Quiz\\questions.txt","C:\\Users\\Stefan\\Documents\\Visual Studio 2015\\Projects\\Quiz\\Quiz\\participants.txt" };
	Controller ctrl{ repo };
	std::vector<Quiz*> windows;
	std::vector<Participant> participants = ctrl.getRepo().getParticipants();
	for (auto p : participants)
	
	{
		windows.push_back(new Quiz{ p, ctrl });
		windows[windows.size() - 1]->setWindowTitle(QString::fromStdString(p.getName()));
	}

	for (auto p : windows) 
	{
		p->show();
	}
	presenter p { ctrl, windows };
	p.show();
	return a.exec();
}
