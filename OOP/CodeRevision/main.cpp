#include "coderevision.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "SourceFile.h"
#include "Programmer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "C:\\Users\\Stefan\\Documents\\Visual Studio 2015\\Projects\\CodeRevision\\CodeRevision\\programmers.txt","C:\\Users\\Stefan\\Documents\\Visual Studio 2015\\Projects\\CodeRevision\\CodeRevision\\sorces.txt" };
	Controller ctrl{ repo };
	std::vector<CodeRevision*> windows;
	std::vector<Programmer> programmers = ctrl.getRepo().getProgrammers();
	for (auto p : programmers)
	{
		windows.push_back(new CodeRevision{ p.getName(), ctrl,windows });
		windows[windows.size() - 1]->setWindowTitle(QString::fromStdString(p.getName()));

	}
	for (auto w : windows)
	{
		w->show();
	}
	
	return a.exec();
}
