#include "Controller.h"


void Controller::addSource(std::string name, std::string creator)
{
	try
	{
		SourceFile sf{ name,creator };
		repo.add(sf);
	}
	catch(std::exception &err)
	{
		throw std::exception(err);
	}
}

Controller::~Controller()
{
}
