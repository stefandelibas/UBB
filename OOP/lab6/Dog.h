#pragma once
#include <iostream>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string source;

public:
	Dog();
	~Dog();
	Dog(const std::string& breed, const std::string& name, const int age, const std::string& source);
	bool operator==(const Dog& d);
	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	int getAge() const { return age; }
	std::string getSource() const { return source; }

	void showPhoto();
};
