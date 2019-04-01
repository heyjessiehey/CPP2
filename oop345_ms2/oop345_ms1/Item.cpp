// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 20, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <iostream>
#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;

Item::Item(const std::string& records){
	//uses an Utilities object (created local in the function)
	//to extract each token from the record and move the Item object accordingly.
	Utilities utilObj;
	size_t next_pos = -1;
	bool more = true;
	if(more)
		m_name = utilObj.extractToken(records, next_pos, more);
	
	if (Item::m_widthField < utilObj.Utilities::getFieldWidth()) {
		Item::m_widthField = utilObj.Utilities::getFieldWidth();
	}

	if(more)
		m_serialNumber =stoi( utilObj.extractToken(records, next_pos, more)); //stoi - string conversion to int
	if (more)
		m_quantity = stoi(utilObj.extractToken(records, next_pos, more));
	if (more)
		m_description = utilObj.extractToken(records, next_pos, more);


	
}

const std::string & Item::getName() const{
	return m_name;
}

const unsigned int Item::getSerialNumber(){
	return m_serialNumber++;
}

const unsigned int Item::getQuantity(){
	return m_quantity;
}

void Item::updateQuantity(){
	if (getQuantity() > 0)
		--m_quantity;
}

void Item::display(std::ostream & os, bool full) const{
	
	if (!full) { //false, this function inserts only the name and serial number
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name
		<< " [" << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << ']' << std::endl;
	}
	else {
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name
			<<" [" <<std::setfill('0') << std::setw(6) << std::right << m_serialNumber << "] "
			<< "Quantity: " << std::setfill(' ') << std::setw(m_widthField) <<std::left << m_quantity
			<< " Description: " << m_description << std::endl;
	}
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
/*
Elliott C.|Gaming PC|CPU|Memory|GPU|GPU|GPU|SSD|Power Supply
Chris S.|Laptop|CPU|Memory|SSD|Power Supply
Mary-Lynn M.|Desktop PC|CPU|Memory|Power Supply
Chris T.|Micro Controller|GPU|GPU|Power Supply|SSD
*/