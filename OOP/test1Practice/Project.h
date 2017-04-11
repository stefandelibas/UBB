#pragma once
#include <iostream>
class Project
{
private:
	std::string name;
	std::string customer;
	std::string date;
	double price;
	bool isDone;

public:
	Project();
	Project(const std::string name, const std::string customer, const std::string date, const double price, const bool isDone);
	std::string getName() const { return name; }
	std::string getCustomer() const { return customer; }
	std::string getDate() const { return date; }
	double getPrice() const { return price; }
	bool getIsDone() const { return isDone; }
	int setDone();
	void setPrice(int price);
	bool operator==(Project p);
	~Project();
};

