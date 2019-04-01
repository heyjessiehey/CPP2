//
// OOP345 Workshop5  - Lambda Expression
// Created by Gayeon Ko on 2018-10-09.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//


#include <iostream>
#include <fstream>
#include "Grades.h"

namespace sict {
	Grades::Grades(std::string file) {
		std::fstream fs(file);
		std::string lines;
		unsigned int count = 0;

		if (fs.is_open()) {
			while (getline(fs, lines)) {
				count++;
			}
			fs.close();
			_size = count;
			_grades = new double[_size];  //need a destructor
			_students = new std::string[_size]; //need a destructor

			fs.open(file);
			count = 0;
			while (getline(fs, lines)) {
				_students[count] = lines.substr(0, lines.find(' '));
				lines.erase(0, lines.find(' '));
				_grades[count] = std::stod(lines.substr(1)); //std::stod() - convert string type to double
				count++;
			}
			fs.close();
		}
		else {
			throw std::string("Failed to open file");
		}
	}

	Grades::~Grades() {
		delete[] _students;
		delete[] _grades;
	}
}