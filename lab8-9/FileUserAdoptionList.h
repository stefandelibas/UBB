#pragma once
#include "UserAdoptionList.h"
class FileUserAdoptionList : public UserAdoptionList
{
protected:
	std::string filename;
public:
	FileUserAdoptionList();
	virtual ~FileUserAdoptionList() {};

	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayUserAdoptionList() const = 0;
};

