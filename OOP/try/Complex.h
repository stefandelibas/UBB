#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
class Complex
{
private:
	int a, b;

public:
	Complex():a{0},b{0}{}
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	Complex(const Complex &c)
	{
		this->a = c.a;
		this->b = c.b;
	}
	int getReal() { return this->a; }
	int getImaginary() { return this->b; }
	bool operator==(Complex c)
	{
		return this->a == c.a && this->b == c.b;
	}
	Complex operator/(int d)
	{
		if (d != 0)
		{
			this->a = this->a / d;
			this->b = this->b / d;
			return *this;
		}
		else
			throw std::exception("Division by zero");

	}
	friend std::ostream& operator<<(std::ostream& os, Complex &c)
	{
		if (c.a == 0 && c.b == 0)
			os << "0";
		else
		{
			if (c.a == 0)
				os << c.b << "i";
			else  
			if (c.b == 0)
					os << c.a;
			
			else
			{
				if (c.b < 0)
					os << c.a << c.b << "i";
				else
					os << c.a << "+" << c.b << "i";
			}
		}
		return os;
	}
	~Complex();
};



