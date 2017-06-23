#pragma once
#include "Question.h"
#include "Participant.h"
#include <vector>

class Repository
{
	std::vector<Question> questions;
	std::vector<Participant> participants;
	std::string fileNameQ;
	std::string fileNameP;

public:
	Repository(std::string fileNameQ,std::string fileNameP);
	std::vector<Question> getQuestions() { return this->questions; }
	std::vector<Participant> getParticipants() { return this->participants; }
	void addQuestion(Question& q);
	void readQuestions();
	void readParticipants();
	void storeQuestions();
	std::string getAnswerOfID(int id);
	void increaseScoreOfParticipant(std::string name, int score);
	int getScore(std::string name);
	~Repository();
private:
	bool findQuestion(Question q);
	
};

