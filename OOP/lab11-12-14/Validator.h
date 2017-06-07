#pragma once
#include <string>
class Validator
{
public:
	Validator();
	bool ValidIntegerNumber(int);
	bool ValidAge(int);
	bool ValidString(std::string);
	~Validator();
};

