//
// Created by Gayeon Ko on 2018-09-20.
//
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "Text.h"

using namespace std;

namespace w2 {
	//Default Constructor        380 nanoseconds - a.size = 0
	Text::Text(){
		m_size = 0;
		m_str = nullptr;
	}

	//Custom Constructor  9982078037 nanoseconds - b.size = 124457
	Text::Text(const string file)  : m_size(0){
		fstream fs(file);
		string lineNumber;
		unsigned int lineCount = 1;

		if (fs.is_open()) {
			while (!fs.eof()) {
				while (getline(fs, lineNumber)) {
					lineCount++;
				}

				m_size = lineCount;
				m_str = new string[m_size];
				
				while (getline(fs, lineNumber)) {
					m_str[lineCount] = lineNumber;
					lineCount++;
				}
			}
		}
		else
			Text();
	}

	// Copy Assignment      422828094 nanoseconds - a.size = 124457
	Text &Text::operator=(const Text &src) {
		if (this != &src) {
			delete[] m_str;
			m_str = new string[src.m_size];
			for (unsigned int i = 0u; i < src.m_size; ++i) {
				m_str[i] = src.m_str[i];
			}
			m_size = src.m_size;
		}
		return *this;
	}
	//Move Assignment            761 nanoseconds - a.size = 124457
	Text &Text::operator=(Text &&src) {
		if (this != &src) {
			delete[] m_str;
			m_str = src.m_str;
			m_size = src.m_size;
			src.m_str = nullptr;
			src.m_size = 0u;
		}
		return *this;
	}

	//copy Constructor     399876151 nanoseconds - c.size = 124457
	Text::Text(const Text &src) {
		*this = src;
	}
	
	//Move Constructor          1141 nanoseconds - d.size = 124457
	Text::Text(Text &&src) {
		*this = move(src);
	}
	
	//Destructor           429119369 nanoseconds
	Text::~Text() {
		delete[] m_str;
	}

	size_t Text::size() const {
		return m_size;
	}
}