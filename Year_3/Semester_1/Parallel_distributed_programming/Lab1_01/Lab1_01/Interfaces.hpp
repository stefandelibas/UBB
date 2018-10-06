#pragma once

#include <string>
#include <vector>
#include <pair>

#ifndef INTERFACES_INCLUDED
#define INTERFACES_INCLUDED

namespace product {

	struct Product
	{
		std::string										m_productName;
		const double									m_price;
		int												m_quantity;
	};

	struct Bill
	{
		std::vector<std::pair<product::Product&,int>>	m_products;
		double											m_totalPrice;
	};
}

#endif // !INTERFACES_INCLUDED