// Name: Gayeon Ko
// Seneca Student ID: 040 704 124
// Seneca email: gko4@myseneca.ca
// Date of completion: Nov 29, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "LineManager.h"
#include "Utilities.h"
/* AssemblyLine.dat
Power Supply|CPU
CPU|GPU
GPU|Memory
Memory|SSD
SSD					*/
LineManager::LineManager(const std::string AssemblyLineFile, 
	std::vector<Task*>& v_tasks, std::vector<CustomerOrder>& v_orders){
	// read the records from AssemblyLine.dat file
	std::ifstream file(AssemblyLineFile);
	if (!file)
		throw std::string("Unable to open [") + AssemblyLineFile + "] file.";
	
	Utilities utilObj;
	size_t next_pos = -1;
	bool more = true;
	std::string record, task, next;
	bool first = true;

	while (!file.eof()){
		std::getline(file, record);
		
		task = utilObj.extractToken(record, next_pos, more);
		if (more) {
			next = utilObj.extractToken(record, next_pos, more);
		}

		for (size_t i = 0; i < v_tasks.size(); ++i) {
			if (v_tasks[i]->getName() == task) {
				if (first) {
					m_firstTask = i;
					first = !first;
				}

				if (!next.empty()) {
					for (size_t j = 0; j < v_tasks.size(); ++j) {
						if (v_tasks[j]->getName() == next) {
							v_tasks[i]->setNextTask(*v_tasks[j]);
							break;
						}
					}
				}
				else {
					m_lastTask = i;
				}
				break;
			}
		}
		next_pos = -1;
		more = true;
		task.clear();
		next.clear();
	}
	for (size_t i = 0; i < v_orders.size(); ++i) {
		ToBeFilled.push_back(std::move(v_orders[i]));
	}
	
	v_orders.erase(v_orders.begin(), v_orders.end());

	AssemblyLine = v_tasks;

}

bool LineManager::run(std::ostream& os){ //filling orders
	bool b = true;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[m_firstTask] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		try {
			AssemblyLine[i]->runProcess(os);
		}
		catch (std::string err) {
			std::cout << std::endl << err << std::endl;
			throw std::string("full inventory");
		}
	}

	CustomerOrder buffer; 
	if (AssemblyLine[m_lastTask]->getCompleted(buffer))
		Completed.push_back(std::move(buffer));

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->moveTask()) {
			b = false;
		}
	}
	return b;
}

void LineManager::displayCompleted(std::ostream& os) const{ //completed orders
	if (!Completed.empty())
		for (size_t i = 0; i < Completed.size(); ++i)
			Completed[i].display(os);
}

void LineManager::validateTasks() const{ //validate Task
	if (!AssemblyLine.empty())
		for (size_t i = 0; i < AssemblyLine.size(); ++i)
			AssemblyLine[i]->validate(std::cout);
}

/*
std::vector<Task*> AssemblyLine; 
std::deque<CustomerOrder> ToBeFilled;
std::deque<CustomerOrder> Completed;
*/

/*Output
=======================
=   Validate Tasks    =
=======================
CPU --> GPU
Memory --> SSD
GPU --> Memory
SSD --> END OF LINE
Power Supply --> CPU

=======================
=   Filling Orders    =
=======================
Filled Elliott C., Gaming PC[Power Supply]
Filled Elliott C., Gaming PC[CPU]
Filled Chris S., Laptop[Power Supply]
Filled Chris S., Laptop[CPU]
Filled Elliott C., Gaming PC[GPU]
Filled Elliott C., Gaming PC[GPU]
Filled Elliott C., Gaming PC[GPU]
Filled Mary-Lynn M., Desktop PC[Power Supply]
Filled Mary-Lynn M., Desktop PC[CPU]
Filled Elliott C., Gaming PC[Memory]
Filled Chris T., Micro Controller[Power Supply]
Filled Chris S., Laptop[Memory]
Filled Elliott C., Gaming PC[SSD]
Filled Mary-Lynn M., Desktop PC[Memory]
Filled Chris T., Micro Controller[GPU]
Filled Chris T., Micro Controller[GPU]
Filled Chris S., Laptop[SSD]
Filled Chris T., Micro Controller[SSD]

=======================
=   Completed Orders  =
=======================
Elliott C. - Gaming PC
[123458] CPU              - FILLED
[654321] Memory           - FILLED
[056789] GPU              - FILLED
[056790] GPU              - FILLED
[056791] GPU              - FILLED
[987654] SSD              - FILLED
[147852] Power Supply     - FILLED
Chris S. - Laptop
[123459] CPU              - FILLED
[654322] Memory           - FILLED
[987655] SSD              - FILLED
[147853] Power Supply     - FILLED
Mary-Lynn M. - Desktop PC
[123460] CPU              - FILLED
[654323] Memory           - FILLED
[147854] Power Supply     - FILLED
Chris T. - Micro Controller
[056792] GPU              - FILLED
[056793] GPU              - FILLED
[147855] Power Supply     - FILLED
[987656] SSD              - FILLED

*/

