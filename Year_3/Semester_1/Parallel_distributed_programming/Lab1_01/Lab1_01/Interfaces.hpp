#pragma once

#include <string>
#include <vector>
#include <map>

#ifndef INTERFACES_INCLUDED
#define INTERFACES_INCLUDED

namespace product {

	struct Product
	{
		std::string										m_productName;
		const double									m_price;
	};

	struct Bill
	{
		int												m_id;
		std::map<product::Product&,int>					m_products;
		double											m_totalPrice;
	};
}

#endif // !INTERFACES_INCLUDED