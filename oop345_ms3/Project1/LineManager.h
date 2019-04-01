// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 29, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef PROJECT1_LINEMANAGER_H
#define PROJECT1_LINEMANAGER_H

#include <string>
#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager{
	std::vector<Task*> AssemblyLine; //A container containing all the references of the Task objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled; //A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed; //A queue of customer orders completed
	unsigned int m_cntCustomerOrder=0; //The number of CustomerOrder objects the assembly line started with.

	size_t m_firstTask;
	size_t m_lastTask;

public:
	LineManager(const std::string, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};

#endif

