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

	void Shop::printProducts(product::Bill & f_bill)
	{
		for (std::map<product::Product &, int>::iterator it = f_bill.m_products.begin(); it != f_bill.m_products.end(); ++it)
		{
			std::cout << it->first.m_productName << " => " << it->second << '\n';
		}
	}

	bool Shop::hasProduct
	(
		product::Bill & f_bill,
		product::Product & f_product,
		int f_quantity
	)
	{
		for (std::map<product::Product &, int>::iterator it = f_bill.m_products.begin(); it != f_bill.m_products.end(); ++it)
		{

			if (it->first.m_productName == f_product.m_productName)
			{
				/*if (m_products[it->first] < f_quantity)
				{
					m.lock();
					m_products[it->first] -= f_quantity;
					m_income += f_quantity * it->first.m_price;
					it->first.m_quantity += f_quantity;
					m.unlock();
				}	*/
				return true;
			}
		}
		
		if (m_products[f_product] < f_quantity)
		{
			m.lock();
			f_bill.m_products.insert(std::pair<product::Product &, int>(f_product, f_quantity));
			m_products[f_product] -= f_quantity;
			m_income += f_quantity * f_product.m_price;
			f_product.m_quantity += f_quantity;
			m.unlock();

			return true;
		}
		else
		{
			return false;
		}
	}

	void Shop::addNewProductToBill(product::Bill & f_bill, product::Product & f_product, int f_quantity)
	{
		bool added = hasProduct(f_bill, f_product, f_quantity);
		if (true == added)
		{
			std::cout << "product:" << f_product.m_productName << " added to bill:" << f_bill.m_id;
		}
		else
		{
			std::cout << "product:" << f_product.m_productName << " failed to be added to bill:" << f_bill.m_id;
		}
		
	}


	int main()
	{
		//random products generator
		

		//random sales


		//final checks for consitency 
	}
}