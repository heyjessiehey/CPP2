#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
#include "Item.h"
#include "Task.h"
#include "Task.h"
#include "CustomerOrder.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Utilities.h"
#include "LineManager.h"
#include "LineManager.h"

using namespace std;

template<typename T>
static void loadFromFile(const char*, vector<T>&);

template<typename T>
static void loadFromFile(const char*, vector<T*>&);


int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	vector<Task*> theTasks;
	vector<CustomerOrder> theOrders;

	Utilities::setDelimiter(',');
	loadFromFile(argv[1], theTasks);
	Utilities::setDelimiter('|');
	loadFromFile(argv[2], theTasks);

	cout << "=======================" << endl;
	cout << "=   Tasks (summary)   =" << endl;
	cout << "=======================" << endl;
	for (const Task* theItem : theTasks)
		theItem->display(cout, false);
	cout << endl;

	cout << "=======================" << endl;
	cout << "=    Tasks (full)     =" << endl;
	cout << "=======================" << endl;
	for (const Task* theItem : theTasks)
		theItem->display(cout, true);
	cout << endl;

	//Select an object and verify all the functionality it working
	cout << "=======================" << endl;
	cout << "=  Manual Validation  =" << endl;
	cout << "=======================" << endl;
	cout << "getName(): " << theTasks[0]->getName() << endl;
	cout << "getSerialNumber(): " << theTasks[0]->getSerialNumber() << endl;
	cout << "getSerialNumber(): " << theTasks[0]->getSerialNumber() << endl;
	cout << "getQuantity(): " << theTasks[0]->getQuantity() << endl;
	theTasks[0]->updateQuantity();
	cout << "getQuantity(): " << theTasks[0]->getQuantity() << endl;
	cout << endl;


	loadFromFile<CustomerOrder>(argv[3], theOrders);

	cout << "=======================" << endl;
	cout << "=        Orders       =" << endl;
	cout << "=======================" << endl;
	for (CustomerOrder& order : theOrders)
		order.display(std::cout);
	cout << endl;

	LineManager lm(argv[4], theTasks, theOrders);
	cout << "=======================" << endl;
	cout << "=   Validate Tasks    =" << endl;
	cout << "=======================" << endl;
	lm.validateTasks();
	cout << endl;

	cout << "=======================" << endl;
	cout << "=   Filling Orders    =" << endl;
	cout << "=======================" << endl;
	while (!lm.run(cout));		//loop running the assembly line until complete
	cout << endl;

	cout << "=======================" << endl;
	cout << "=   Completed Orders  =" << endl;
	cout << "=======================" << endl;
	lm.displayCompleted(cout);
	cout << endl;

	cout << "=======================" << endl;
	cout << "=  Inventory (full)   =" << endl;
	cout << "=======================" << endl;
	for (const Item* theItem : theTasks)
		theItem->display(cout, true);
	cout << endl;

	// cleanup
	for (const Task* task : theTasks)
		delete task;

	return 0;
}

template<typename T>
static void loadFromFile(const char* filename, vector<T>& theCollection)
{
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		T elem(record);
		theCollection.push_back(std::move(elem));
	}

	file.close();
}

template<typename T>
static void loadFromFile(const char* filename, vector<T*>& theCollection)
{
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		theCollection.push_back(new T(record));
	}

	file.close();
}

/*
Command Line: ms3 Inventory1.dat Inventory2.dat CustomerOrders.dat AssemblyLine.dat

=======================
=   Tasks (summary)   =
=======================
CPU          [123456]
Memory       [654321]
GPU          [056789]
SSD          [987654]
Power Supply [147852]

=======================
=    Tasks (full)     =
=======================
CPU          [123456] Quantity: 5            Description: Central Processing Unit
Memory       [654321] Quantity: 10           Description: Basic Flash Memory
GPU          [056789] Quantity: 7            Description: General Porcessing Unit
SSD          [987654] Quantity: 5            Description: Solid State Drive
Power Supply [147852] Quantity: 20           Description: Basic AC Power Supply

=======================
=  Manual Validation  =
=======================
getName(): CPU
getSerialNumber(): 123456
getSerialNumber(): 123457
getQuantity(): 5
getQuantity(): 4

=======================
=        Orders       =
=======================
Elliott C. - Gaming PC
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] SSD              - MISSING
[000000] Power Supply     - MISSING
Chris S. - Laptop
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] SSD              - MISSING
[000000] Power Supply     - MISSING
Mary-Lynn M. - Desktop PC
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] Power Supply     - MISSING
Chris T. - Micro Controller
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] Power Supply     - MISSING
[000000] SSD              - MISSING

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

=======================
=  Inventory (full)   =
=======================
CPU          [123461] Quantity: 1            Description: Central Processing Unit
Memory       [654324] Quantity: 7            Description: Basic Flash Memory
GPU          [056794] Quantity: 2            Description: General Porcessing Unit
SSD          [987657] Quantity: 2            Description: Solid State Drive
Power Supply [147856] Quantity: 16           Description: Basic AC Power Supply


*/