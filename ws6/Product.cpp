//
// OOP345 Workshop 6  - STL Containers
// Created by Gayeon Ko on 2018-10-30.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//

#include <iomanip>
#include "Product.h"

namespace w6{

    double Product::getPrice() const {
        return m_cost;
    }

    void Product::display(std::ostream& os) const {
		os << std::setw(16) << m_prodNum <<
			std::fixed << std::setw(16) << std::setprecision(2) << m_cost;
    }
}