#include "SourceFile.h"


SourceFile::SourceFile(std::string & name, std::string & creator)
{
	this->name = name;
	this->status = "not_revised";
	this->creator = creator;
}

void SourceFile::changeStatus(std::string &reviewer)
{
	this->status = "revised";
	this->reviewer = reviewer;
}

std::string SourceFile::toString()
{
	std::string s;
	s = this->name + ";" + this->status + ";" + this->creator + ";" + this->reviewer;

	return s;
}

SourceFile::~SourceFile()
{
}
