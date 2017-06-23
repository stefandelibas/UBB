#pragma once
class Action
{
public:
	Action();
	virtual void execute() = 0;
	virtual ~Action();
};

