#pragma once
#include "FileUserAdoptionList.h"
class HTMLUserAdoptionList : public FileUserAdoptionList
{
public:
	void writeToFile() override;
	void displayUserAdoptionList() const override;
};
