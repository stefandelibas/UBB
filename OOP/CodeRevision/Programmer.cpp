#include "Programmer.h"



Programmer::Programmer(std::string & n, int numberOfFilesToRevise)
{
	this->name = n;
	this->toRevise = numberOfFilesToRevise;
	this->revised = 0;
}

Programmer::~Programmer()
{
}
