#include "Repository.h"
#include <fstream>
#include "Utils.h"

Repository::Repository(std::string fileNP, std::string fileNS)
{
	this->fileNameP = fileNP;
	this->fileNameS = fileNS;
	this->readProgrammers();
	this->readSourceFiles();
}

void Repository::readProgrammers()
{
	std::ifstream fin(this->fileNameP);
	while (!fin.eof())
	{
		std::string line;
		getline(fin, line);
		std::vector<std::string> tokens = tokenize(line, ';');
		std::string name;
		int toRevise;
		if (tokens.size() == 2)
		{
			name = tokens[0];
			toRevise = stoi(tokens[1]);
		}
		Programmer p{ name, toRevise };
		this->programmers.push_back(p);
	}
}

void Repository::readSourceFiles()
{
	std::ifstream fin(this->fileNameS);
	while (!fin.eof())
	{
		std::string line;
		getline(fin, line);
		std::vector<std::string> tokens = tokenize(line, ';');
		std::string name;
		std::string creator;
		std::string reviewer;
		if (tokens.size() == 4)
		{
			name = tokens[0];
			creator = tokens[2];
			SourceFile sf{ name,creator };
			this->sources.push_back(sf);
		}
	}
}

void Repository::storeSorceFiles()
{
	std::ofstream fout(this->fileNameS);
	for (auto s : this->sources)
	{
		std::string str = s.toString();
		fout << str;
	}
	fout.close();
}

void Repository::reviseOne(std::string &sourceName, std::string &reviewer)
{
	for (int i = 0; i < this->sources.size(); i++)
	{
		if (this->sources[i].getName() == sourceName)
		{
			this->sources[i].changeStatus(reviewer);
		}
	}
	for (int i = 0; i < this->programmers.size(); i++)
	{
		if (this->programmers[i].getName() == reviewer)
		{
			this->programmers[i].reviseOne();
		}
	}
}

int Repository::getToRevise(std::string name)
{
	for (auto p : this->programmers)
	{
		if (p.getName() == name)
			return p.getToRevise();
	}
	
}

int Repository::getRevised(std::string name)
{
	for (auto p : this->programmers)
	{
		if (p.getName() == name)
			return p.getRevised();
	}
}

std::string Repository::getStatusOF(std::string sourceName)
{
	for (auto sf : this->sources)
	{
		if (sf.getName() == sourceName)
			return sf.getStatus();
	}
}

void Repository::add(SourceFile & s)
{
	if (this->findSource(s) == false)
	{
		this->sources.push_back(s);
	}
	else
		throw std::exception("SourceFile already exists!");
}

bool Repository::findSource(SourceFile sf)
{
	for (auto s : this->sources)
	{
		if (s.getName() == sf.getName())
			return true;
	}
	return false;
}

Repository::~Repository()
{
}
