//
// OOP345 Workshop5  - Lambda Expression
// Created by Gayeon Ko on 2018-10-09.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//

#ifndef OOP345_WS5_LETTER_H
#define OOP345_WS5_LETTER_H

#include <string>

namespace sict {
	enum Letter { Ap, A, Bp, B, Cp, C, Dp, D, F }; // integral type that can represent all enumerator values

	template <typename T> //a template function
	std::string convertGrades(const T& index) { // this should return "value" not reference or address otherwise, it occurses bad_alloc
		std::string grade; // this should be inside the template, otherwise it occurses a linker error becuase it become a global variable
		switch (index) {
		case Ap:
			grade = "A+  ";
			break;
		case A:
			grade = "A   ";
			break;
		case Bp:
			grade = "B+  ";
			break;
		case B:
			grade = "B   ";
			break;
		case Cp:
			grade = "C+  ";
			break;
		case C:
			grade = "C   ";
			break;
		case Dp:
			grade = "D+  ";
			break;
		case D:
			grade = "D   ";
			break;
		default:
			grade = "F   ";
		}
		return grade;
	}
}


#endif //OOP345_WS5_LETTER_H
