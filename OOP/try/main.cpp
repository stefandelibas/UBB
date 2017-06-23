#include <iostream>
#include <string>
#include "Complex.h"
#include"Vector.h"
#include <iterator> 
#include <deque>
#include "Stack.h"
#include <assert.h>
#include <cstring>

using namespace std;

class Ex1
{
public:
	Ex1() { cout << "Exception1\n"; }
	Ex1(const Ex1& ex) { cout << "Copy_ex1\n"; }
};
class Ex2 : public Ex1
{
public:
	Ex2() { cout << "Exception2\n"; }
	Ex2(const Ex2& ex) { cout << "Cpoy_exc2\n"; }
};

void except(int x)
{
	if (x < 0)
		throw Ex1{};
	else if (x == 0)
		throw Ex2{};
	cout << "DOne";
}
/*
class B
{
public :
	void f() { cout << "B.f "; }
	virtual ~B() { }
};
class D1 : public B
{
public:
	virtual void f() { cout << "D1.f "; }
	virtual ~D1() {  }
};
class D2 : public D1
{
public:
	void f() { cout << "D2.f "; }
};

class Vectorr
{
	int* elems;
	int  capacity;
public:
	Vectorr() : capacity{ 0 } { elems = new int[10]; }
	void add(int elem) {
		elems[ capacity++] = elem;
	}
	int& operator[](int pos) {
		if (pos < 0 || pos >=  capacity)
			throw std::exception{ "Index out of bounds." };
		return elems[pos];
	}
	~Vectorr() { delete[] elems; }
};

class B
{
	public:
	B()   
	{
		std::cout<<"B{}";
	}
	virtual	void print() { std::cout << "B"; }
	virtual	~B() { std::cout << "~B()"; }
};
class D	:public	B
{
public	:
	D() {std::cout	<<"D{}"	;}
	void print()override { std::cout << "D"; }
	virtual	~D() {std::cout << "~D()";}
};
*/
class E
{
public:
	E() { std::cout << "E{}"; }
	virtual ~E() { std::cout << "~E()"; }
};
class DE :public E
{
public:
	static int n;
	DE() { n++; }
};
int DE::n = 0;

int fct2(int x)
{
	if (x < 0)
	{
		throw E{};
		std::cout << "number less than 0\n";
	}
	else if (x == 0)
	{
		throw DE{};
		std::cout << "number equal to 0\n";
	}
	return x % 10;
}

int main()
{

	Stack<std::string>s{ 2 };
	assert(s.maxCapacity() == 2);
	try
	{
		s = s + "exam";
		s += "oop";
		s = s + "test";
	}
	
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	cout << s.pop();
	cout << s.pop();




	/*
	std::deque<std::string> d;
	d.push_back("A");
	d.push_front("B");
	d.push_back("C");
	d.push_front("D");

	auto itBegin = d.begin();
	auto itEnd = d.end();
	itBegin++;
	itEnd--;
	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
		itBegin++;
	}
	
	try
	{
		int res = 0;
		res = fct2(-5);
		std::cout << DE::n;
		res = fct2(0);
		std::cout << DE::n;
		res = fct2(25);
		std::cout << DE::n;
	}
	catch (E&)
	{
		std::cout << DE::n;
	}
	/*
	B* b[] = { new B{},new D{} };
	b[0]->print();
	b[1]->print();
	delete b[0];
	delete b[1];

	
	Vectorr v1;
	v1.add(0);
	v1.add(1);
	//Vectorr v2 = v1;
	try {
		v1[0] = 2;
		cout << v1[0] << " " << v1[1] << " ";
		cout << endl;
		//cout << v2[0] << " " << v2[1] << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what();
	}
	

	B* b1 = new B{}; b1->f(); delete b1;
	B* b2 = new D1{}; b2->f(); delete b2;
	B* b3 = new D2{}; b3->f(); delete b3;
	D1* d = new D2{}; d->f(); delete d;

	
	Complex c{}, a{ 1,2 }, b{ 2,-2 }, d{ 0,-3 }, e{ 3,0 };
	//std::cout << a << b << c << d << e;

	Vector<string> v1{ vector<string>{"hello","bye"} };
	v1.printAll(cout);
	cout << "\n";
	Vector<Complex> v2{ vector<Complex>{a,b,c,d} };
	v2.printAll(cout);
	cout << "\n";


	vector<int> v{ 1,2,3,4,5 };
	vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
	v.insert(it, 8);

	for (auto a : v)
		cout << a << " ";

	cout << endl;
	it = v.end() - 1;
	*it = 10;

	for (auto a : v)
		cout << a << " ";
	cout << endl;

	vector<int>x;
	std::copy_if(v.begin(), v.end(), back_inserter(x), [](int a) {return a % 2 == 0; });
	int i = std::count_if(x.begin(), x.end(), [](int a) {return a % 2 == 0; });
	cout << i << "\n";
	for (auto a : x)
		cout << a << " ";

	
	try
	{
		cout << "Start";
		
		try
		{
			except(0);
		}
		catch (Ex2& e) {}
		
		except(-2);
	}
	catch (Ex1 e) {}
	*/





	int ceva;
	cin >> ceva;
	system("pause");
	return 0;
}