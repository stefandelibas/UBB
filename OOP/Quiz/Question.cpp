#include "Question.h"



Question::Question(int id, std::string &text, std::string &answer, int score)
{
	this->id = id;
	this->text = text;
	this->answer = answer;
	this->score = score;
}

std::string Question::toString()
{
	std::string s = std::to_string(this->getID()) + ";" + this->getText() + ";" + this->getAnswer() + ";" + std::to_string(this->getScore()) + "\n";
	return s;
}

Question::~Question()
{
}
