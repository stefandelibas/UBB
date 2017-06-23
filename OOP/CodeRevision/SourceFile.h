#pragma once
#include <string>

class SourceFile
{
private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviewer;

public:
	SourceFile(std::string &name, std::string &creator);
	std::string getName() { return this->name; }
	std::string getStatus() { return this->status; }
	std::string getCreator() { return this->creator; }
	std::string getReviewer() { return this->reviewer; }
	void changeStatus(std::string &reviewer);	
	std::string toString();
	~SourceFile();
};

