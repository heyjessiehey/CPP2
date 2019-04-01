// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 29, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"

char Utilities::m_delimiter = ' ';

// sets the field width of the current object to the value of the parameter 
void Utilities::setFieldWidth(size_t width){
	m_widthField = width;
}

size_t Utilities::getFieldWidth() const{
	return m_widthField;
}

//extracts tokens from the first parameter
const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more){
	size_t current_pos = next_pos + 1; 
	next_pos = str.find_first_of(m_delimiter, current_pos); //uses the delimiter to extract the next token from str starting at next_pos.
	(next_pos == std::string::npos) ? more = false : more = true;//If successful, it returns the extracted token found and sets more to true; false otherwise.

	std::string token = str.substr(current_pos, next_pos - current_pos);
	
	if (token.empty()) {// reports an exception if there are two delimiters with no token between them.
		more = false;
		throw std::string(str + "ERROR: No Token");
	}
	// This function updates the current object¡¯s m_widthField data member 
	// if its current value is less than the size of the token extracted.
	if (Utilities::m_widthField < token.length()) {
		Utilities::m_widthField = token.length();
	}
	return token;
}

void Utilities::setDelimiter(const char delimiter){
	m_delimiter = delimiter;
}

const char Utilities::getDelimiter() const{
	return m_delimiter;
}

/*
CPU,123456,5,Central Processing Unit
Memory,654321,10,Basic Flash Memory
GPU,56789,7,General Porcessing Unit
*/
/*
SSD|987654|5|Solid State Drive
Power Supply|147852|20|Basic AC Power Supply
*/