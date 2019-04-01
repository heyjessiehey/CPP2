//
// Created by Gayeon Ko on 2018-09-20.
//

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <fstream>
#include <utility>


namespace w2 {
	class Text {
		std::string* m_str;
		size_t m_size; // represent sizes and counts, type returned by the sizeof operator
	public:
		Text(); // default constructor
		Text(const std::string file); // one argument constructor
		Text(const Text& src); // a copy constructor
		Text& operator=(const Text& src); // a copy assignment operator
		Text(Text&& src); // a move constructor
		Text& operator=(Text&& src); // a move assignment operator
		~Text(); // a destructor
		size_t size() const; // a member function: returns the number of records of text data


	};
}

#endif //OOP345_WS2_TEXT_H
