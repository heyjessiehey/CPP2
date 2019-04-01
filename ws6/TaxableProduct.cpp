//
// OOP345 Workshop  6  - STL Containers
// Created by Gayeon Ko on 2018-10-30.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//
#include<iomanip>
#include "TaxableProduct.h"
namespace w6{
	const double TaxableProduct::taxRate[] = { 1.13, 1.08 };

	TaxableProduct::TaxableProduct(std::string prodNum, double price, char taxCode) : Product(prodNum, price) {
		if (taxCode == 'H')
			m_taxtype = 0;
		else if (taxCode == 'P')
			m_taxtype = 1;
	}
	double TaxableProduct::getPrice() const {
		return Product::getPrice() * taxRate[m_taxtype];
	}

	const char* TaxableProduct::getTaxType() const {
		return m_taxtype == 0 ? "HST" : "PST";
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << std::setw(4) << getTaxType();
	}
}

/*
10012 34.56
10023 45.67 H
10234 12.32 P
10056 67.54
20202 11.22 C
10032  2.34 H
10029 54.12
04301 84.00 H
10044 17.89 P
10035 96.30
10001 44.12 M
00004  8.01
*/