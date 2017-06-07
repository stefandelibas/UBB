#include "FileUserAdoptionList.h"

FileUserAdoptionList::FileUserAdoptionList() : UserAdoptionList{}, filename{ "" }
{
}

void FileUserAdoptionList::setFilename(const std::string& filename)
{
	this->filename = filename;
}