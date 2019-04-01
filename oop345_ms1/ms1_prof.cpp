#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
#include "Item.h"
#include "Utilities.h"
#include "Utilities.h"

using namespace std;

static bool loadInventory(const char*, vector<Item>&);

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	//**************//
	vector<Item> theInventory;
	Utilities::setDelimiter(',');
	loadInventory(argv[1], theInventory);
	Utilities::setDelimiter('|');
	loadInventory(argv[2], theInventory);

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


	return 0;
}

bool loadInventory(const char* filenameInv, vector<Item>& theInventory)
{
	std::ifstream file(filenameInv);
	if (!file)
		throw string("Unable to open [") + filenameInv + "] file";

	// each line from the file represents an item;
	// read one at a time and add it to the inventory
	string theRecord;
	while (!file.eof())
	{
		std::getline(file, theRecord);
		Item newItem(theRecord);
		theInventory.push_back(std::move(newItem));
	}
	file.close();
	return true;
}
/*
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

*/