#pragma once
#include <vector>
#include "Programmer.h"
#include "SourceFile.h"

class Repository
{
private:
	std::vector<Programmer> programmers;
	std::vector<SourceFile> sources;
	std::string fileNameP, fileNameS;
public:
	Repository(std::string fileNP,std::string fileNS);
	std::vector<Programmer> getProgrammers() { return this->programmers; }
	std::vector<SourceFile> getSourceFiles() { return this->sources; }
	void readProgrammers();
	void readSourceFiles();
	void storeSorceFiles();
	void changeStatusOF(std::string sourceName, std::string &reviewer);
	std::string getStatusOF(std::string sourceName);
	void add(SourceFile &s);
	bool findSource(SourceFile sf);
	void reviseOne(std::string &sourceName, std::string &reviewer);
	int	getToRevise(std::string name);
	int getRevised(std::string name);
	~Repository();
};

