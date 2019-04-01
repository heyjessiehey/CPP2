// Workshop 8 - Smart Pointers
// Element.h
//
// OOP345 Workshop 8  - Smart Pointer
// Created by Gayeon Ko on 2018-11-12.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//
#ifndef W8_ELEMENT_H
#define W8_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w8 {

    struct Description {
        unsigned code;
        std::string desc;
        bool load(std::ifstream& f)
		{
            f >> code >> desc;
            return f.good();
        }

		void display(std::ostream& os) const
		{
            os << std::setw(FWC) << code
			   << std::setw(FWD) << desc
			   << std::endl;
        }
    };

    struct Price {
        unsigned code;
        double price;
        bool load(std::ifstream& f)
		{
            f >> code >> price;
            return f.good();
        }

		void display(std::ostream& os) const
		{
            os << std::setw(FWC) << code << std::setw(FWP)
            << price << std::endl;
        }
    };

    struct Product {
        std::string desc;
        double price;
		int m_id;
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;
		Product()
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
        Product(const std::string& str, double p)
		{
			this->desc = str;
			this->price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		Product(const Product& other)
		{
			this->desc = other.desc;
			this->price = other.price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
			          << "] from [" << other.m_id << "]"
			          << std::endl;
		}
		~Product()
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl; 
		}

		// TODO: add the validate() function here
		inline void validate() {
			if (price < 0) {// call destructor in Product and then catch block
				throw std::string("*** Negative prices are invalid ***"); 
			}
		}

        void display(std::ostream& os) const
		{
            os << std::setw(FWD) << desc
			   << std::setw(FWP) << price
			   << std::endl;
        }
    };
}
#endif