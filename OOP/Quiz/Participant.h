#pragma once
#include <string>
class Participant
{
	std::string name;
	int score;
public:
	Participant(std::string name);
	std::string getName() { return this->name; }
	void incScore(int score) { this->score += score; }
	int getScore() { return this->score; }
	~Participant();
};

