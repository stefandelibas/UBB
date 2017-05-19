#include "Validator.h"



Validator::Validator()
{
}

bool Validator::ValidIntegerNumber(int n)
{
	return (n < 0);
}

bool Validator::ValidAge(int n)
{
	return n < 100;
}

bool Validator::ValidString(std::string s)
{
	return (s == "");
}


Validator::~Validator()
{
}
