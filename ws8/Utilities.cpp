//
// OOP345 Workshop 8  - Smart Pointer
// Created by Gayeon Ko on 2018-11-12.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t a = 0; a < price.size(); ++a) {
				if (desc[i].code == price[a].code) {
					Product* ptr = new Product(desc[i].desc, price[a].price);
					ptr->validate(); //calling the function validate()
					priceList += ptr;
					delete ptr;
					ptr = nullptr;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t a = 0; a < price.size(); ++a) {
				if (desc[i].code == price[a].code) {
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[a].price));
					ptr->validate(); //calling the function validate()
					priceList += ptr;
					ptr = nullptr;
				}
			}
		}

		return priceList;
	}
}

/*
4662 tomatoes
4039 cucumbers
4056 brocoli
4067 lemons
4068 oranges


4067 0.99
4068 0.67
4039 1.99
4056 -2.49


4067 0.99
4068 0.67
4039 1.99
4056 2.49

*/