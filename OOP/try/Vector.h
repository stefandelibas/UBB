#pragma once
#include<vector>
#include<iostream>
template < typename T>
class Vector 
{
private:
	T* elems;
	int  capacity;

public:
	Vector(std::vector<T> v)
	{
		this-> capacity = v. capacity();
		this->elems = new T[this-> capacity];
		for (int i = 0; i < v. capacity(); i++)
		{
			this->elems[i] = v[i];
		}
	}
	void printAll(std::ostream& os)
	{
		for (int i = 0; i < this-> capacity-1; i++)
		{
			os << this->elems[i] << ",";
		}
		os << this->elems[this-> capacity - 1];
	}






};