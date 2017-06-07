#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>

using namespace std;


Dog::Dog() : breed(""), name(""), age{ 0 }, source("") {}
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


istream & operator >> (istream & is, Dog& d)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;

	d.breed = tokens[0];
	d.name = tokens[1];
	d.age = stoi(tokens[2]);
	d.source = tokens[3];

	return is;
}

ostream & operator<<(ostream & os, const Dog & d)
{
	os << d.breed << "," << d.name << "," << d.age << "," << d.source << "\n";
	return os;
}


