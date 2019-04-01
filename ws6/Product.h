//
// OOP345 Workshop  6  - STL Containers
// Created by Gayeon Ko on 2018-10-30.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca
//

#ifndef OOP345_WS6_PRODUCT_H
#define OOP345_WS6_PRODUCT_H

#include <string>
#include "iProduct.h"

namespace w6 {
    class Product : public iProduct {
		std::string m_prodNum;
        double m_cost;
    public:
        Product()= default;
        Product(std::string no, double cost) : m_prodNum(no), m_cost(cost){}
        double getPrice() const;
        void display(std::ostream&) const;
    };
}
#endif //OOP345_WS6_PRODUCT_H
