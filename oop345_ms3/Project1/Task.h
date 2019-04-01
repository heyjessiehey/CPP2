// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 29, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef PROJECT1_TASK_H
#define PROJECT1_TASK_H

#include <deque>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item{
	std::deque<CustomerOrder> m_orders; //new CustomerOrders coming in one side and exiting out the other once filled.
	Task* m_pNextTask; //a pointer to the next task on the assembly line
public:
	Task(const std::string&);
	Task(const Task&) = delete; //copy constructor
	Task& operator=(const Task&) = delete; // copy assignemnt operator
	Task(Task&&) = delete; //move constructor
	Task& operator=(Task&&) = delete; //move assignemnt operator
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif


/* AssemblyLine.dat
Power Supply|CPU
CPU|GPU
GPU|Memory
Memory|SSD
SSD
*/
