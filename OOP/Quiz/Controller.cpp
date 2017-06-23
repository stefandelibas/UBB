#include "Controller.h"


void Controller::addQuestion(int id, std::string& text, std::string& answer, int score)
{
	try
	{
		Question q{ id,text,answer,score };
		this->repo.addQuestion(q);
	}
	catch (const std::invalid_argument& err) { throw err; }
}

void Controller::storeToFile()
{
	this->repo.storeQuestions();
}

std::string Controller::getCorrectAnswer(int id)
{
	return repo.getAnswerOfID(id);
}

void Controller::increaseScore(std::string name, int score)
{
	this->repo.increaseScoreOfParticipant(name,score);
}

int Controller::getScore(std::string name)
{
	return this->repo.getScore(name);
}

Controller::~Controller()
{
}
