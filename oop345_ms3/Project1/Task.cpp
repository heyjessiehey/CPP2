// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 29, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Task.h"

//A Task object manages a single Item on the assembly line.

/* A Task object represents a single location on the assembly line for filling
items into customer orders.*/
Task::Task(const std::string& record) : Item(record) {
	m_pNextTask = nullptr;
	
}

//runs a single cycle of the assembly line for the current task.
void Task::runProcess(std::ostream& os){
	if (!m_orders.empty()) {
		if (!m_orders.front().getOrderFillState()) {
			while (!m_orders.front().getItemFillState(getName())) {
				m_orders.front().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask(){
	if (!m_orders.empty()) {
		if (m_pNextTask) {
			if (m_orders.front().getItemFillState(getName())) {
				*m_pNextTask += std::move(m_orders.front());
				m_orders.pop_front();
			}
		}
		return true;
	}else{
		return false;
	}
}

void Task::setNextTask(Task& nextTask){
	m_pNextTask = &nextTask;
}

bool Task::getCompleted(CustomerOrder& order){
	if (!m_orders.empty() && m_orders.front().getOrderFillState()) {
		order = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}else {
		return false;
	}
}

void Task::validate(std::ostream& os){
	std::string str;
	str = m_pNextTask ? m_pNextTask->getName() : "END OF LINE";
	os << getName() << " --> " << str << std::endl;
}

Task& Task::operator+=(CustomerOrder&& order){
	m_orders.push_back(std::move(order));
	return *this;
}

/* Item
CPU,123456,5,Central Processing Unit
Memory,654321,10,Basic Flash Memory
GPU,56789,7,General Porcessing Unit
*/
/*
SSD|987654|5|Solid State Drive
Power Supply|147852|20|Basic AC Power Supply
*/

/* CustomerOrder
Elliott C.|Gaming PC|CPU|Memory|GPU|GPU|GPU|SSD|Power Supply
Chris S.|Laptop|CPU|Memory|SSD|Power Supply
Mary-Lynn M.|Desktop PC|CPU|Memory|Power Supply
Chris T.|Micro Controller|GPU|GPU|Power Supply|SSD
*/

/* AssemblyLine.dat
Power Supply|CPU
CPU|GPU
GPU|Memory
Memory|SSD
SSD
*/