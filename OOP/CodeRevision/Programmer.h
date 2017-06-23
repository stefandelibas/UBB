#pragma once
#include <string>

class Programmer
{
private:
	std::string name;
	int revised;
	int toRevise;
public:
	Programmer(std::string &n,int numberOfFilesToRevise);
	int getRevised() { return this->revised; }
	std::string getName() { return this->name; }
	int getToRevise() { return this->toRevise;}
	bool operator=(Programmer p) { return this->name == p.name; }
	void reviseOne()
	{
		this->revised = this->revised + 1;
		this->toRevise = this->toRevise - 1;
	}
	~Programmer();
};

