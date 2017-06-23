#pragma once
#include <string>

class Question
{
	int id,score;
	std::string text, answer;
public:
	Question(int id,std::string& text,std::string& answer,int score);
	int getID() { return this->id; }
	std::string getText() { return this->text; }
	std::string getAnswer() { return this->answer; }
	int getScore() { return this->score; }
	std::string toString();
	bool operator==(Question q)
	{
		return this->id == q.id;
	}
	~Question();
};

