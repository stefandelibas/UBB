#include "Repository.h"
#include "Controller.h"
#include "UI.h"

int main()
{
	Repository repo{};

	Project p1{ "project1","Customer1","2017.02.03",5,0 };
	Project p2{ "project2","Customer2","2017.02.04",6,0 };
	Project p3{ "project3","Customer3","2017.02.05",7,1 };
	Project p4{ "project4","Customer4","2017.09.10",4,0 };
	Project p5{ "project5","Customer5","2017.08.10",4,1 };
	Project p6{ "project6","Customer6","2017.07.10",4,1 };
	Project p7{ "project7","Customer7","2017.06.10",4,1 };
	Project p8{ "project8","Customer8","2017.05.10",4,0 };
	Project p9{ "project9","Customer9","2017.04.10",4,0 };
	Project p10{ "project10","Customer10","2017.03.10",4,1 };

	repo.addProject(p1);
	repo.addProject(p2);
	repo.addProject(p3);
	repo.addProject(p4);
	repo.addProject(p5);
	repo.addProject(p6);
	repo.addProject(p7);
	repo.addProject(p8);
	repo.addProject(p9);
	repo.addProject(p10);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.runUI();

	return 0;
}