// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 20, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MILESTONE_CUSTOMERORDERS_H
#define MILESTONE_CUSTOMERORDERS_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Utilities.h"

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;
	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder{
	std::string m_name; //the name of the customer (e.g., John, Sara, etc)
	std::string m_product; //the name of the product being assembled (Desktop, Laptop, etc)
	unsigned int m_cntItem=0; //a count of the number of items for the customer's order
	ItemInfo** m_ListItem;
	static size_t m_widthField; //the maximum width of a field, used for display purposes
public:
	CustomerOrder();
	CustomerOrder(std::string&); //custom constructor
	CustomerOrder(const CustomerOrder&); //copy constructor - throw an exception
	CustomerOrder& operator=(const CustomerOrder&)= delete; //copy operator
	CustomerOrder(CustomerOrder&&) noexcept; // move constructor - Not throw exceptions
	CustomerOrder& operator=(CustomerOrder&&); // move assignment operator
	~CustomerOrder();

	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;
};


#endif

/*
Elliott C.|Gaming PC|CPU|Memory|GPU|GPU|GPU|SSD|Power Supply
Chris S.|Laptop|CPU|Memory|SSD|Power Supply
Mary-Lynn M.|Desktop PC|CPU|Memory|Power Supply
Chris T.|Micro Controller|GPU|GPU|Power Supply|SSD
*/