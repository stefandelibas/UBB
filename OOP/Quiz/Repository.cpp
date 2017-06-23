#include "Repository.h"
#include <fstream>
#include "Utils.h"

Repository::Repository(std::string fileNameQ, std::string fileNameP)
{
	this->fileNameP = fileNameP;
	this->fileNameQ = fileNameQ;
	this->readParticipants();
	this->readQuestions();
}

void Repository::addQuestion(Question &q)
{
	/*
	if (q.getText() == "")
		throw std::invalid_argument("Question text cannot be empty");
	*/
	
	{
		if (this->findQuestion(q) == false)
		{
			this->questions.push_back(q);
		}
		else
			throw std::invalid_argument("Question already in repository");
	}
}

void Repository::readParticipants()
{
	std::ifstream fin(this->fileNameP);
	while (!fin.eof())
	{
		std::string line;
		getline(fin, line);
		std::vector<std::string> tokens = tokenize(line, ';');
		int score;
		std::string name;
		if (tokens.size() == 1)
		{
			name = tokens[0];
		}
		Participant p{ name };
		this->participants.push_back(p);
	}
}

void Repository::readQuestions()
{
	std::ifstream fin(this->fileNameQ);
	while (!fin.eof())
	{
		std::string line;
		getline(fin, line);
		std::vector<std::string> tokens = tokenize(line, ';');
		int id,score;
		std::string text, answer;
		if (tokens.size() == 4)
		{
			id = stoi(tokens[0]);
			text = tokens[1];
			answer = tokens[2];
			score = stoi(tokens[3]);
			Question q{ id,text,answer,score };
			this->questions.push_back(q);
		}
	}
}

void Repository::storeQuestions()
{
	std::ofstream fout(this->fileNameQ);
	for (auto q : this->questions)
	{
		std::string s = q.toString();
		fout << s;
	}
	fout.close();
}

std::string Repository::getAnswerOfID(int id)
{
	for (auto q : this->questions)
		if (q.getID() == id)
			return q.getAnswer();
}

void Repository::increaseScoreOfParticipant(std::string name, int score)
{
	for(int i=0;i<this->participants.size();i++)
	{
		if (this->participants[i].getName() == name)
		{
			this->participants[i].incScore(score);
			break;
		}
	}
}

int Repository::getScore(std::string name)
{
	for (auto p : this->participants)
	{
		if (p.getName() == name)
		{
			return p.getScore();
		}
	}
}


bool Repository::findQuestion(Question q)
{
	for (auto currentQ : this->questions)
	{
		if (currentQ == q)
			return true;
	}
	return false;
}

Repository::~Repository()
{
}
