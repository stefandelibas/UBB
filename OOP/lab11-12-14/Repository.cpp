#include "Repository.h"
#include <string>
#include <fstream>

Repository::Repository(std::string file)
{
	this->file = file;
	this->loadFromFile();
}

Repository::~Repository()
{
}

void Repository::addDog(const Dog& d)
{
	if (findDog(d) != -1)
		throw std::invalid_argument("The dog already exists!");
	this->dogs.push_back(d);
	this->storeToFile();
}
void Repository::deleteDog(const Dog& d)
{
	int i = findDog(d);
	if (i == -1)
		throw std::invalid_argument("Could not find the dog!");
	this->dogs.erase(this->dogs.begin() + i);
	this->storeToFile();
}

void Repository::updateDog(const Dog& d)
{
	int i = findDog(d);
	if (i != -1)
	{
		this->dogs[i] = d;
		this->storeToFile();
	}
	else
		throw std::invalid_argument("Could not find the dog!");
}

int Repository::findDog(const Dog d)
{
	for (size_t i = 0; i<this->dogs.size(); i++)
	{
		if (this->dogs[i] == d)
		{
			return i;
		}
	}
	return -1;
}

std::string Repository::getLink(std::string breed, std::string name)
{
	int i = findDog(Dog{ breed,name,0,"" });
	return this->dogs[i].getSource();
}

void Repository::loadFromFile()
{
	std::ifstream fin(this->file);
	size_t n;
	fin >> n;
	for (size_t i = 0; i<n; i++)
	{
		std::string breed;
		std::string name;
		int age;
		std::string source;
		fin.get();
		getline(fin, breed);
		getline(fin, name);
		getline(fin, source);
		fin >> age;
		this->dogs.push_back(Dog(breed, name, age, source));
	}
	fin.close();
}

void Repository::storeToFile()
{
	std::ofstream fout(this->file);
	fout << this->dogs.size() << '\n';
	for (size_t i = 0; i<this->dogs.size(); i++)
	{
		fout << dogs[i].getBreed() << '\n';
		fout << dogs[i].getName() << '\n';
		fout << dogs[i].getSource() << '\n';
		fout << dogs[i].getAge() << '\n';
	}
	fout.close();
}





