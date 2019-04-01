 // Workshop 8 - Smart Pointers
 // List.h
//
// OOP345 Workshop 8  - Smart Pointer
// Created by Gayeon Ko on 2018-11-12.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//
#ifndef W8_LIST_H
#define W8_LIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace w8 {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		void operator+=(const std::unique_ptr<T>& ptr) {
			list.push_back(*ptr);
		}


		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* ptr) { // call copy constructor in Product
			list.push_back(*ptr);
		}


		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif