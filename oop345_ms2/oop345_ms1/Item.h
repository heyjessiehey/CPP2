// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 20, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MILESTONE_ITEM_H
#define MILESTONE_ITEM_H

#include <string>

class Item{
	std::string m_name;  // name of the item
	std::string m_description; //description of the item
	int m_serialNumber; // the next serial number to be assigned on the assembly line
	int m_quantity; // the number of current items left in stock
	static size_t m_widthField; //the maximum characters to be displayed for a field
					  //All Item objects share the same m_widthField
public:
	// custom constructor
	Item(const std::string&);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif

