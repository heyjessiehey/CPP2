//
// OOP345 Workshop 6  - STL Containers
// Created by Gayeon Ko on 2018-10-30.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//

#include <fstream>
#include "ProdUtil.h"
#include "TaxableProduct.h"

namespace w6 {

    std::ostream& operator<<(std::ostream& os, const iProduct& p) {
        p.display(os);
        return os;
    }

    iProduct* readProduct(std::ifstream& file) {
        iProduct* prod = nullptr;
        std::string no;
        double cost;
		char tax = file.peek();

		
		if (tax!=EOF) {
			file >> no >> cost;
			tax = file.get();
			if (tax == ' ') {
				file >> tax;
				if (tax == 'H') {
					TaxableProduct* temp = new TaxableProduct(no, cost, tax);
					prod = temp;
				}
				else if (tax == 'P') {
					TaxableProduct* temp = new TaxableProduct(no, cost, tax);
					prod = temp;
				}
				else if (tax == 'M' || tax == 'C') {
					throw std::string("Unrecognizable Tax Code!");
				}
			}
			else {
				Product* temp = new Product(no, cost);
				prod = temp;
			}
		}
		else {
			prod = nullptr;
		}
        return prod;
    }
}
