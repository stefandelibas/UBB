#pragma once
#include <iostream>
#include <algorithm>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string source;
	static int i;
public:
	Dog();
	~Dog();
	Dog(const std::string& breed, const std::string& name, const int age, const std::string& source);
	bool operator==(const Dog& d);
	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	int getAge() const { return age; }
	static int getInstances() { return i; }
	std::string getSource() const { return source; }

	void showPhoto();

	friend std::istream& operator >> (std::istream& is, Dog& d);
	friend std::ostream& operator<<(std::ostream& os, const Dog& d);
};
