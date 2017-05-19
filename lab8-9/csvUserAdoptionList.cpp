#include "csvUserAdoptionList.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void csvUserAdoptionList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw std::invalid_argument("The file could not be opened!");

	for (auto s : this->adoptedDogs)
		f << s;

	f.close();
}

void csvUserAdoptionList::displayUserAdoptionList() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "%ProgramFiles%\Windows NT\Accessories\wordpad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
