#pragma once

#include "Interfaces.hpp"

namespace shop
{
	class Shop
	{
	public:

		std::vector<product::Bill>						m_bills;
		std::vector<std::pair<product::Product, int>>	m_products;
		double											m_income;

		Shop()
		{
			m_income = 0;
		}

		void addNewBill
		(
			const product::Bill& f_bill
		);

		void addNewProductToBill
		(
			const product::Bill& f_bill,
			const product::Product& f_product,
			int f_quantity
		);
	};
}