#include <iostream>
#include <thread>
#include <mutex>
#include <iterator>
#include "Interfaces.hpp"
#include "Shop.hpp"

std::mutex m;

namespace shop
{
	
	void Shop::addNewBill(const product::Bill& bill)
	{
		m.lock();
		m_bills.push_back(bill);
		m.unlock();
	
	}
	void Shop::addNewProductToBill(const product::Bill & f_bill, const product::Product & f_product, int f_quantity)
	{
		m.lock();
		std::iterator<int> itr{ f_bill.m_products.begin() };
		while(itr != f_bill.m_products.end()){
			itr++;

		}
		if (f_bill.m_product.)
		{
			f_bill.m_products.push_back(std::pair<product::Product, int>(f_product, 1));
		}
		else
		{

		}
		m.unlock();
	}


	int main()
	{
		//random products generator
		

		//random sales


		//final checks for consitency 
	}
}