#pragma once
#include "FileUserAdoptionList.h"
class csvUserAdoptionList : public FileUserAdoptionList
{
public:
	void writeToFile() override;
	void displayUserAdoptionList() const override;
};

