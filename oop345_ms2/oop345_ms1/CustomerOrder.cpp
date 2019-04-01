// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 20, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> //std::all_of
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(){
	 m_name=nullptr; //the name of the customer (e.g., John, Sara, etc)
	 m_product=nullptr; //the name of the product being assembled (Desktop, Laptop, etc)
	 m_cntItem = 0; //a count of the number of items for the customer's order
	 m_ListItem=nullptr;
	//a dynamically allocated array of pointers.Each element of the array is a dynamically allocated object of type ItemInfo(see below).
	//This is the resource that your class must manage
}

CustomerOrder::CustomerOrder(std::string& records){
	Utilities utilObj;
	size_t next_pos = -1;
	bool more = true;
	std::vector < std::string>  v_itemname;

	if (more) {
		m_name = utilObj.extractToken(records, next_pos, more);
	}

	if (more) {
		m_product = utilObj.extractToken(records, next_pos, more); 
	}

	while (more) {
		v_itemname.push_back(utilObj.extractToken(records, next_pos, more));
		m_cntItem++;
	}

	if (CustomerOrder::m_widthField < utilObj.Utilities::getFieldWidth()) {
		CustomerOrder::m_widthField = utilObj.Utilities::getFieldWidth();
	}

	m_ListItem = new ItemInfo*[m_cntItem];

	for (size_t i = 0; i < v_itemname.size(); ++i) {
		m_ListItem[i] = new ItemInfo(v_itemname[i]);
	}
}

// copy constructor
CustomerOrder::CustomerOrder(const CustomerOrder& src){
	throw 1;
}
//move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}
//move assignment operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src){
	if (this != &src) {
		//delete[] m_ListItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_ListItem = src.m_ListItem;

		src.m_name = '\0';
		src.m_product = '\0';
		src.m_cntItem = 0;
		src.m_ListItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder(){
	for (unsigned int i = 0; i <m_cntItem ;++i) {
		delete m_ListItem[i];
	}
	delete[] m_ListItem;
}
/*
getOrderFillState(): MISSING
Filled Mary-Lynn M., Desktop PC[CPU]
Filled Mary-Lynn M., Desktop PC[Memory]
Filled Mary-Lynn M., Desktop PC[Power Supply]
getOrderFillState(): FILLED
*/

//getItemFillState("CPU"): FILLED
bool CustomerOrder::getItemFillState(std::string item) const{
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_ListItem[i]->m_itemName == item) {
			return m_ListItem[i]->m_fillState;
		}
	}
	return true; //If the item doesn¡¯t exist in the order, return true
}

bool CustomerOrder::getOrderFillState() const{
	std::vector<bool> v_temp;
	bool temp;
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		v_temp.push_back(m_ListItem[i]->m_fillState);
	}
	temp = std::all_of(v_temp.begin(), v_temp.end(), [](bool v) {return v; });
	return temp;
}
//Filled Mary-Lynn M., Desktop PC[CPU]
void CustomerOrder::fillItem(Item& item, std::ostream& os){
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_ListItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() > 0) {
				m_ListItem[i]->m_serialNumber = item.getSerialNumber();
				m_ListItem[i]->m_fillState = true;
				item.updateQuantity();
				os << "Filled " << m_name << ", " << m_product << '[' << m_ListItem[i]->m_itemName << ']' << std::endl;
			}
			else { //item found but inventory is empty
				os << "Unable to fill " << m_name << ", " << m_product << '[' << m_ListItem[i]->m_itemName << ']' << std::endl;
			}
		}
	}


}

void CustomerOrder::display(std::ostream& os) const{
	os << m_name << " - " << m_product << std::endl;

	for (unsigned int i = 0; i < m_cntItem ; ++i) {
		std::string str;
		str = (m_ListItem[i]->m_fillState) ? "FILLED" : "MISSING";
		os << '[' << std::setfill('0') << std::setw(6) << m_ListItem[i]->m_serialNumber << "] ";
		os << std::setfill(' ') << std::setw(m_widthField) << m_ListItem[i]->m_itemName << " - " << str;
		os << std::endl;
	}
}

/*
Elliott C.|Gaming PC|CPU|Memory|GPU|GPU|GPU|SSD|Power Supply
Chris S.|Laptop|CPU|Memory|SSD|Power Supply
Mary-Lynn M.|Desktop PC|CPU|Memory|Power Supply
Chris T.|Micro Controller|GPU|GP
*/