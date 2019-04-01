// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	try {
		Grades grades(argv[1]); // create obj with data file

		//lambda expression (letter) that converts a numeric grade to its letter equivalent
		// using the letter enumeration and template function in Letter.h
		auto letter = [](double grade) {
			int index;
			if (grade >= 90 && grade <= 100) {
				index = Ap;
			}
			else if (grade >= 80 && grade < 90) {
				index = A;
			}
			else if (grade >= 75 && grade < 80) {
				index = Bp;
			}
			else if (grade >= 70 && grade < 75) {
				index = B;
			}
			else if (grade >= 65 && grade < 70) {
				index = Cp;
			}
			else if (grade >= 60 && grade < 65) {
				index = C;
			}
			else if (grade >= 55 && grade < 60) {
				index = Dp;
			}
			else if (grade >= 50 && grade < 55) {
				index = D;
			}
			else {
				index = F;
			}
			return index;
		};
		grades.displayGrades(std::cout, letter);
	}
	catch (const char* err) {           // adding the code to report an exception
		std::cout << err << std::endl;
	}

	return 0;
}

/*
Command Line: ws w5_grades.dat
   1022342 67.40 C+
   1024567 73.50 B
   2031456 79.30 B+
   6032144 53.50 D
   1053250 92.10 A+
   3026721 86.50 A
   7420134 62.30 C
   9762314 58.70 D+
 */
