//
// OOP345 Workshop5  - Lambda Expression
// Created by Gayeon Ko on 2018-10-09.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//

#ifndef OOP345_WS5_GRADES_H
#define OOP345_WS5_GRADES_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Letter.h"


namespace sict {
	class Grades {
		std::string *_students=nullptr;
		double *_grades=nullptr;
		size_t _size=0; //size_t - Alias of one of the fundamental unsigned integer types.
	public:
		Grades(std::string file); 

		//tmeplate member function
		template<typename F>
		void displayGrades(std::ostream &os, F lambda) const {
			for (size_t i = 0; i < _size; ++i) {
				int idx = lambda(_grades[i]); // using lambda expression getting an index of grade in "enum Letter"
				std::string gradeLetter = convertGrades(idx); // convertGrades should return value, so string variable gradeLetter is able to catch it
				os << "   " << _students[i] << ' '
					<< std::fixed << std::setprecision(2) << _grades[i] // std::setprecision(int n) always require an argument
					<< ' ' << gradeLetter << std::endl;
			}
		}

		//Your design prohibits copying, moving and assigning of a Grades object.
		Grades(const Grades &) = delete; // copy constructor
		Grades(Grades &&) = delete; // move constructor
		Grades &operator=(const Grades &) = delete; // copy assignment
		Grades &operator=(Grades &&) = delete; // move assignment

		~Grades(); // need destructor becuase dynamic allocation
	};
}
#endif //OOP345_WS5_GRADES_H


/* decimal point
#include <iostream>     // std::cout, std::ios
int temp = std::cout.precision(); // temp is 6

cout.precision(42); //a member function


vs


#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

cout << setprecision(42); // IO manipulator


*/