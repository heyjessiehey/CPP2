#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
#include "Item.h"
#include "CustomerOrder.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Utilities.h"

using namespace std;

template<typename T>
static void loadFromFile(const char*, vector<T>&);

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	vector<Item>          theInventory;
	vector<CustomerOrder> theOrders;

	{
		// Milestone 1
		Utilities::setDelimiter(',');
		loadFromFile<Item>(argv[1], theInventory);
		Utilities::setDelimiter('|');
		loadFromFile<Item>(argv[2], theInventory);

		cout << "=======================" << endl;
		cout << "= Inventory (summary) =" << endl;
		cout << "=======================" << endl;
		for (Item& theItem : theInventory)
			theItem.display(cout, false);
		cout << endl;

		cout << "=======================" << endl;
		cout << "=  Inventory (full)   =" << endl;
		cout << "=======================" << endl;
		for (Item& theItem : theInventory)
			theItem.display(cout, true);
		cout << endl;

		//Select an object and verify all the functionality it working
		cout << "=======================" << endl;
		cout << "=  Manual Validation  =" << endl;
		cout << "=======================" << endl;
		cout << "getName(): " << theInventory[0].getName() << endl;
		cout << "getSerialNumber(): " << theInventory[0].getSerialNumber() << endl;
		cout << "getSerialNumber(): " << theInventory[0].getSerialNumber() << endl;
		cout << "getQuantity(): " << theInventory[0].getQuantity() << endl;
		theInventory[0].updateQuantity();
		cout << "getQuantity(): " << theInventory[0].getQuantity() << endl;
		cout << endl;
	}

	{
		// Milestone 2
		loadFromFile<CustomerOrder>(argv[3], theOrders);

		cout << "=======================" << endl;
		cout << "=        Orders       =" << endl;
		cout << "=======================" << endl;
		for (CustomerOrder& order : theOrders)
			order.display(std::cout);
		cout << endl;

		//Select an object and verify all the functionality it working
		cout << "=======================" << endl;
		cout << "=  Manual Validation  =" << endl;
		cout << "=======================" << endl;
		cout << "CustomerOrders::display(): "; // Test #1
		theOrders[theOrders.size() - 1].display(cout);
		cout << endl;

		try
		{
			// copy constructor
			cout << "CustomerOrders::CustomerOrders(&): "; // Test #2
			CustomerOrder anOrder(theOrders[0]);
		}
		catch (...)
		{
			cout << "----> ERROR: Cannot make copies.";
			cout << endl << endl;
		}

		// move constructor
		cout << "CustomerOrders::CustomerOrders(&&): "; // Test #3
		CustomerOrder tmp(std::move(theOrders[theOrders.size() - 1]));
		theOrders.pop_back();
		tmp.display(cout);
		cout << endl;

		cout << "CustomerOrders::CustomerOrders(string): "; // Test #4
		string strRecord = "Chloe/Flight PC/CPU/GPU/Power Supply";
		Utilities::setDelimiter('/');
		CustomerOrder tmp2(strRecord);
		tmp2.display(cout);
		cout << endl;

		cout << "CustomerOrders::operator=(&&): "; // Test #5
		tmp2 = std::move(theOrders[theOrders.size() - 1]);
		theOrders.pop_back();
		tmp2.display(cout);
		cout << endl;
		/*
		Mary - Lynn M. - Desktop PC
			[000000] CPU - MISSING
			[000000] Memory - MISSING
			[000000] Power Supply - MISSING
		*/
		cout << "CustomerOrders::fillItem()" << endl; // Test #6
		cout << "getOrderFillState(): "
		     << (tmp2.getOrderFillState() ? "FILLED" : "MISSING")
		     << endl;

		tmp2.fillItem(theInventory[0], cout);
		cout << "getItemFillState(\"CPU\"): "
			 << (tmp2.getItemFillState("CPU") ? "FILLED" : "MISSING")
		     << endl;

		cout << "getOrderFillState(): "
		     << (tmp2.getOrderFillState() ? "FILLED" : "MISSING")
		     << endl;

		for (size_t i = 0; i < theInventory.size(); i++)
			tmp2.fillItem(theInventory[i], cout);

		cout << "getOrderFillState(): "
		     << (tmp2.getOrderFillState() ? "FILLED" : "MISSING")
		     << endl;
	}
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

/*
Command Line: ms2 Inventory1.dat Inventory2.dat CustomerOrders.dat

=======================
= Inventory (summary) =
=======================
CPU          [123456]
Memory       [654321]
GPU          [056789]
SSD          [987654]
Power Supply [147852]

=======================
=  Inventory (full)   =
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
=  Manual Validation  =
=======================
CustomerOrders::display(): Chris T. - Micro Controller
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] Power Supply     - MISSING
[000000] SSD              - MISSING

CustomerOrders::CustomerOrders(&): ----> ERROR: Cannot make copies.

CustomerOrders::CustomerOrders(&&): Chris T. - Micro Controller
[000000] GPU              - MISSING
[000000] GPU              - MISSING
[000000] Power Supply     - MISSING
[000000] SSD              - MISSING

CustomerOrders::CustomerOrders(string): Chloe - Flight PC
[000000] CPU              - MISSING
[000000] GPU              - MISSING
[000000] Power Supply     - MISSING

CustomerOrders::operator=(&&): Mary-Lynn M. - Desktop PC
[000000] CPU              - MISSING
[000000] Memory           - MISSING
[000000] Power Supply     - MISSING

CustomerOrders::fillItem()
getOrderFillState(): MISSING
Filled Mary-Lynn M., Desktop PC[CPU]
getItemFillState("CPU"): FILLED
getOrderFillState(): MISSING
Filled Mary-Lynn M., Desktop PC[CPU]
Filled Mary-Lynn M., Desktop PC[Memory]
Filled Mary-Lynn M., Desktop PC[Power Supply]
getOrderFillState(): FILLED

*/