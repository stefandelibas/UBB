#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository &repo;
public:
	Controller(Repository &r) :repo{ r } {};
	void addQuestion(int id, std::string& text, std::string& answer, int score);
	void storeToFile();
	std::string getCorrectAnswer(int id);
	void increaseScore(std::string name, int id);
	int getScore(std::string name);
	Repository getRepo() { return this->repo; }
	~Controller();
};

