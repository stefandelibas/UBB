#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>

Dog::Dog() : breed(""), name(""), age{ 0 },source("") {}
int Dog::i = 0;
Dog::Dog(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->source = source;
	i++;
}

bool Dog::operator==(const Dog& d)
{
	return getName() == d.getName() && getBreed() == d.getBreed();
}

Dog::~Dog()
{
}

void Dog::showPhoto()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

