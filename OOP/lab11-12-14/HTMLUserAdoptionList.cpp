#include "HTMLUserAdoptionList.h"
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

void HTMLUserAdoptionList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw std::invalid_argument("The file could not be opened!");
	f << "<!DOCTYPE html><head><title>Adoption List</title></head><body><table border = 1><tr><td>Name</td><td>Breed</td><td>Age</td><td>Photo</td></tr>";
	for (auto d : this->adoptedDogs)
	{
		f << "<tr>";
		std::string s;
		int age = d.getAge();
		s = "<td>" + d.getBreed() + "</td>" + "<td>" + d.getName() + "</td>" + "<td>" + std::to_string(age) + "</td>" + "<td>" + " <img src=" + d.getSource() + "height=50 width=50>" + "</td>";
		f << "</tr>";
		f << s.c_str();
	}
	f << "</table></body></html>";
	f.close();
}

void HTMLUserAdoptionList::displayUserAdoptionList() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
