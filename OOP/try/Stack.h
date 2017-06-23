#pragma once
#include <vector>
#include <string>
template <typename T>
class Stack
{
private:
	int capacity;
	std::vector<T> elems;
public:
	Stack() {};
	Stack(int s)
	{
		this->capacity = s;
	}
	void push(T e)
	{
		if (this->elems.size() < capacity)
		{
			this->elems.push_back(e);
		}
		else
			throw std::exception("Stack is full!");
	}
	T pop()
	{
		if (this->elems.size())
		{
			T top = this->elems[this->elems.size() - 1];
			this->elems.pop_back();
			return top;
		}
		else
			throw std::exception("Empty stack!");
	}
	int maxCapacity() { return this->capacity; }
	Stack& operator+(T e)
	{
		this->push(e);
		return *this;
	}
	Stack operator+=(T e)
	{
		this->push(e);
		return *this;
	}
	std::vector<T> getElems() { return this->elems; }
	~Stack() {};
};
