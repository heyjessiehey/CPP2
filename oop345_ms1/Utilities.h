// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 8, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef OOP345_MS1_UTILITIES_H
#define OOP345_MS1_UTILITIES_H

#include <string>

class Utilities{
	size_t m_widthField = 1; //specifying the length of the token extracted; used for display purpose later
	static char m_delimiter;
public:
	Utilities() = default;
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;
};

#endif