#pragma once
class UndoAction
{
public:
	virtual void executeUndo() = 0;
	virtual ~UndoAction() {}
};

