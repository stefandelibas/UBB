#pragma once

#include "Interfaces.hpp"

namespace shop
{
	class Shop
	{
	public:

		std::vector<product::Bill>						m_bills;
		std::map<product::Product&, int>				m_products;
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
			product::Bill&						f_bill,
			product::Product&				f_product,
			int									f_quantity
		);
		void printProducts
		(
			product::Bill &						f_bill
		);
		bool hasProduct
		(
			product::Bill &						f_bill,
			product::Product &			f_product,
			int f_quantity
		);
	};
}