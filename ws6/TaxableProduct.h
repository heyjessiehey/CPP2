//
// OOP345 Workshop 6  - STL Containers
// Created by Gayeon Ko on 2018-10-30.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//

#ifndef OOP345_WS6_TAXABLEPRODUCT_H
#define OOP345_WS6_TAXABLEPRODUCT_H

#include <array>
#include "Product.h"

namespace w6 {
	class TaxableProduct : public Product {
		int m_taxtype;
		static const double taxRate[2];
	public:
		TaxableProduct(std::string, double, char);
		double getPrice() const;
		const char* getTaxType() const;
		void display(std::ostream&) const;
	};
}


#endif //OOP345_WS6_TAXABLEPRODUCT_H


//derives from Product and holds additional information about the product’s taxable status
//The same tax rates apply to all TaxableProduct objects.
// Use a class array (an array of class variables;i.e., static member)
// to store the tax rates for HST and PST tax codes (13% and 8%)