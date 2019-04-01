// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    std::ifstream productList(argv[1]);
    if (!productList) {
        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
        return 2;
    }
    std::cout << std::fixed << std::setprecision(2);

    // TODO: Define a variable of type vector named "products"
    std::vector<w6::iProduct*> products;

    std::cout << "====================================\n";
    std::cout << "Reading data from the file\n";
    std::cout << "====================================\n";
    {
        // TODO: Read from the file one record at a time and create a product.
        // - Print a message before starting processing a product.
        // - Add the product to the vector "products", created above.
        // - Handle any thrown exceptions and print the message.
        w6::iProduct* temp = nullptr;
        int i = 1;
        do {
            std::cout << "Processing record " << i << ": ";
            try {
                temp = w6::readProduct(productList);
                if (temp) {
                    products.push_back(temp);
                    std::cout << "done!" << std::endl;
                } else {
                    std::cout << "no such record! Reached the end of the file!" << std::endl;
                }
            }
            catch (std::string err) {
                std::cout << err << std::endl;
            };
            ++i;
        } while (temp != nullptr);
    }
    std::cout << "====================================\n";

    std::cout << std::endl;
    std::cout << "====================================\n";
    std::cout << "Printing the content of the vector\n";
    std::cout << "====================================\n";

    double total = 0.0;
	std::cout << std::setw(16) << " Product No" << std::setw(17)<< "Taxable\n";
    std::cout << "------------------------------------\n";
    for (auto i = 0u; i < products.size(); i++) {
        total += products[i]->getPrice();
        std::cout << *products[i];
		std::cout << std::endl;
    }
    std::cout << "------------------------------------\n";
    std::cout << std::setw(22) <<"Total: ";
    std::cout << std::setw(10) << total << std::endl;
    std::cout << "====================================\n";

    return 0;
}

/*
Command Line: ws sales.dat
====================================
Reading data from the file
====================================
Processing record 1: done!
Processing record 2: done!
Processing record 3: done!
Processing record 4: done!
Processing record 5: Unrecognizable Tax Code!
Processing record 6: done!
Processing record 7: done!
Processing record 8: done!
Processing record 9: done!
Processing record 10: done!
Processing record 11: Unrecognizable Tax Code!
Processing record 12: done!
Processing record 13: no such record! Reached the end of the file!
====================================

====================================
Printing the content of the vector
====================================
      Product No         Taxable
------------------------------------
           10012           34.56
           10023           45.67 HST
           10234           12.32 PST
           10056           67.54
           10032            2.34 HST
           10029           54.12
           04301           84.00 HST
           10044           17.89 PST
           10035           96.30
           00004            8.01
------------------------------------
               Total:     442.33
====================================
 */

